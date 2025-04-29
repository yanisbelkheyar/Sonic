#include "crypto_aead.h"
#include "aux_functions.h"
#include "round_procrastinate_inter.h"
#include "function.h"
#include <stdlib.h>
#include <stdio.h>


//Sonic Duplex
int crypto_aead_encrypt(
    unsigned char *c,unsigned long long *clen,
    const unsigned char *m,unsigned long long mlen,
    const unsigned char *ad,unsigned long long adlen,
    const unsigned char *nsec,
    const unsigned char *npub,
    const unsigned char *k
  )
  {

    (void)nsec;
    *clen = mlen+16;

    const uint64_t iv[2] = {0x0,0x0};
    const uint64_t key[4] =   {set_word(k,0),set_word(k,8),set_word(k,16),set_word(k,24)};
    const uint64_t nonce[2] = {set_word(npub,0),set_word(npub,8)};

    //initialization
    h_state512 left  = {.data_64 = {iv[0],iv[1],nonce[0],nonce[1]},.size_64=4};
    h_state512 right = {.data_64 = {key[0],key[1],key[2],key[3]},.size_64=4};
    const h_state512 key_state  = right;
    sonic_encrypt_512_procrastinate(&left,&right);
    XOR2(&right,&key_state);

    uint64_t cur_absorbe[4] = {0,0,0,0};
    unsigned long long ad_id = 0;

    //absorbtion additional data
    while(adlen>=32){
        
        add_to_state_half(&left,ad+ad_id);
        sonic_encrypt_512_procrastinate(&left,&right);

        adlen -= 32;
        ad_id += 32;

    }
    if(adlen>=1){

        cur_absorbe[0] = 0;
        cur_absorbe[1] = 0;
        cur_absorbe[2] = 0;
        cur_absorbe[3] = 0;

        for(int i=0;i<adlen;i++){
            cur_absorbe[i>>3] ^=(uint64_t) ad[ad_id+i] << ((7-(i & 7))<<3);
        }
        cur_absorbe[adlen>>3] ^= (uint64_t)80<<((7-(adlen & 7))<<3);
        add_byte(left.data_64,cur_absorbe,adlen,left.data_64);
        sonic_encrypt_512_procrastinate(&left,&right);
    }
    
    right.data_64[3] ^= (uint64_t)1;

    //process plaintext
    unsigned long long m_id = 0;
    while(mlen>=32){

        add_to_state_half(&left, m+m_id);
        extract_ciphertext_full(&left,c+m_id);
        sonic_encrypt_512_procrastinate(&left,&right);

        mlen -= 32;
        m_id += 32;

    }

    if(mlen>=1){

        cur_absorbe[0] = 0;
        cur_absorbe[1] = 0;
        cur_absorbe[2] = 0;
        cur_absorbe[3] = 0;

        for(int i=0;i<mlen;i++){
            cur_absorbe[i>>3] ^= (uint64_t)m[m_id+i] << ((7-(i & 7))<<3);
        }
        cur_absorbe[mlen>>3] ^= (uint64_t)0x80<<((7-(mlen & 7))<<3);
        add_byte(left.data_64,cur_absorbe,mlen,left.data_64);
        extract_ciphertext_partial(&left,c+m_id,mlen);
    }else
    if(mlen==0){
        cur_absorbe[0] = (uint64_t)0x80 << 56;
        add_byte(left.data_64,cur_absorbe,1,left.data_64);
    }

    //finalization
    XOR2(&right,&key_state);
    sonic_encrypt_512_procrastinate(&left,&right);
    XOR2(&right,&key_state);
    extract_tag(&right,c+m_id + mlen);
    return 0;

}

int crypto_aead_decrypt(
    unsigned char *m,unsigned long long *mlen,
    unsigned char *nsec,
    const unsigned char *c,unsigned long long clen,
    const unsigned char *ad,unsigned long long adlen,
    const unsigned char *npub,
    const unsigned char *k
  )
  {

    (void)nsec;
    *mlen = clen - 16;

    const uint64_t iv[2] = {0x0,0x0};
    const uint64_t key[4] =   {set_word(k,0),set_word(k,8),set_word(k,16),set_word(k,24)};
    const uint64_t nonce[2] = {set_word(npub,0),set_word(npub,8)};

    //initialization
    h_state512 left  = {.data_64 = {iv[0],iv[1],nonce[0],nonce[1]},.size_64=4};
    h_state512 right = {.data_64 = {key[0],key[1],key[2],key[3]},.size_64=4};

    const h_state512 key_state  = {.data_64={key[0],key[1],key[2],key[3]},.size_64=4};
    sonic_encrypt_512_procrastinate(&left,&right);

    XOR2(&right,&key_state);

    uint64_t cur_absorbe[4] = {0,0,0,0};
    unsigned long long ad_id = 0;

    //absorbtion additional data
    while(adlen>=32){
        
        add_to_state_half(&left,ad+ad_id);
        sonic_encrypt_512_procrastinate(&left,&right);

        adlen -= 32;
        ad_id += 32;

    }
    if(adlen>=1){

        cur_absorbe[0] = 0;
        cur_absorbe[1] = 0;
        cur_absorbe[2] = 0;
        cur_absorbe[3] = 0;

        for(int i=0;i<adlen;i++){
            cur_absorbe[i>>3] ^=(uint64_t) ad[ad_id+i] << ((7-(i & 7))<<3);
        }
        cur_absorbe[adlen>>3] ^= (uint64_t)80<<((7-(adlen & 7))<<3);
        add_byte(left.data_64,cur_absorbe,adlen,left.data_64);
        sonic_encrypt_512_procrastinate(&left,&right);
    }
    
    right.data_64[3] ^= (uint64_t)1;

    clen -= 16;
    //process plaintext
    unsigned long long m_id = 0;
    while(clen>=32){

        add_to_state_half(&left,c+m_id);
        extract_ciphertext_full(&left,m+m_id);
        replace_full(c,m_id,32,&left);

        sonic_encrypt_512_procrastinate(&left,&right);

        clen -= 32;
        m_id += 32;

    }

    if(clen>=1){

        cur_absorbe[0] = 0;
        cur_absorbe[1] = 0;
        cur_absorbe[2] = 0;
        cur_absorbe[3] = 0;

        for(int i=0;i<clen;i++){
            cur_absorbe[i>>3] ^= (uint64_t)c[m_id+i] << ((7-(i & 7))<<3);
        }
        cur_absorbe[clen>>3] ^= (uint64_t)0x80<<((7-(clen & 7))<<3);

        add_byte(left.data_64,cur_absorbe,clen,left.data_64);
        extract_ciphertext_partial(&left,m+m_id,clen);
        replace(cur_absorbe,clen,left.data_64);
    }
    else
    if(clen==0){
        cur_absorbe[0] = (uint64_t)0x80 << 56;
        add_byte(left.data_64,cur_absorbe,1,left.data_64);
    }

    //finalization
    XOR2(&right,&key_state);
    sonic_encrypt_512_procrastinate(&left,&right);
    XOR2(&right,&key_state);


    unsigned char tag[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    extract_tag(&right,tag);

    int correct = 0;
    for(int i=0;i<16;i++){
        if((tag[i]!=c[(*mlen)+i])){ 
            correct = 1;
        }
    }

    if(correct==1) return -1;
    else return 0;

}