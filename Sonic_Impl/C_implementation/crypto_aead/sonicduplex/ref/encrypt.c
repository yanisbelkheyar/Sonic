#include "crypto_aead.h"
#include "aux_functions.h"
#include "round_procrastinate.h"
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
    int size_64 = 8;
    int h_size_64 = 4;
    uint64_t state[8] = {0,0,0,0,0,0,0,0};

    const uint64_t iv[2] = {0x0,0x0};
    const uint64_t key[4] =   {set_word(k,0),set_word(k,1),set_word(k,2),set_word(k,3)};
    const uint64_t nonce[2] = {set_word(npub,0),set_word(npub,1)};

    //initialization

    state[4] = key[0];
    state[5] = key[1];
    state[6] = key[2];
    state[7] = key[3];

    state[0] = iv[0];
    state[1] = iv[1];
    state[2] = nonce[0];
    state[3] = nonce[1];

    sonic_encrypt_512_procrastinate(state,state);
    add_key_to_state(state,key,4);

    uint64_t cur_absorbe[4] = {0,0,0,0};
    unsigned long long ad_id = 0;

    //absorbtion additional data
    
    while(adlen>=32){
        
        add_to_state_full(state,ad,ad_id);
        sonic_encrypt_512_procrastinate(state,state);

        adlen -= 32;
        ad_id += 32;

    }

    if(adlen>=1){

        for(int i=0;i<adlen;i++){
            cur_absorbe[i>>3] ^=(uint64_t) ad[ad_id+i] << ((7-(i & 7))<<3);
        }
        cur_absorbe[adlen>>3] ^= (uint64_t)80<<((7-(adlen & 7))<<3);
        add_byte(state,cur_absorbe,adlen,state);
        sonic_encrypt_512_procrastinate(state,state);
    }
    
    state[7] ^= (uint64_t)1;

    //process plaintext
    unsigned long long m_id = 0; 

    while(mlen>=32){

        add_to_state_full(state,m,m_id);
        extract_ciphertext(state,c,m_id,32);

        sonic_encrypt_512_procrastinate(state,state);

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
        add_byte(state,cur_absorbe,mlen,state);
        extract_ciphertext(state,c,m_id,mlen);
    }
    else
    if(mlen==0){
        cur_absorbe[0] = (uint64_t)0x80 << 56;
        add_byte(state,cur_absorbe,1,state);
    }

    //finalization

    add_key_to_state(state,key,4);
    sonic_encrypt_512_procrastinate(state,state);
    add_key_to_state(state,key,4);
    extract_ciphertext(state+6,c,*clen-16,16);

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

    int size_64 = 8;
    int h_size_64 = 4;
    uint64_t state[8] = {0,0,0,0,0,0,0,0};

    const uint64_t iv[2] = {0x0,0x0};
    const uint64_t key[4] =   {set_word(k,0),set_word(k,1),set_word(k,2),set_word(k,3)};
    const uint64_t nonce[2] = {set_word(npub,0),set_word(npub,1)};

    //initialization

    state[4] = key[0];
    state[5] = key[1];
    state[6] = key[2];
    state[7] = key[3];

    state[0] = iv[0];
    state[1] = iv[1];
    state[2] = nonce[0];
    state[3] = nonce[1];

    sonic_encrypt_512_procrastinate(state,state);
    add_key_to_state(state,key,4);

    uint64_t cur_absorbe[4] = {0,0,0,0};
    unsigned long long ad_id = 0;
    
    //absorbtion additional data
    while(adlen>=32){
        
        add_to_state_full(state,ad,ad_id);
        sonic_encrypt_512_procrastinate(state,state);

        adlen -= 32;
        ad_id += 32;

    }

    if(adlen>=1){

        for(int i=0;i<adlen;i++){
            cur_absorbe[i>>3] ^=(uint64_t) ad[ad_id+i] << ((7-(i & 7))<<3);
        }
        cur_absorbe[adlen>>3] ^= (uint64_t)80<<((7-(adlen & 7))<<3);
        add_byte(state,cur_absorbe,adlen,state);
        sonic_encrypt_512_procrastinate(state,state);
    }
    
    state[7] ^= (uint64_t)1;

    clen -= 16;
    //process plaintext
    unsigned long long m_id = 0;

    while(clen>=32){

        add_to_state_full(state,c,m_id);
        extract_ciphertext(state,m,m_id,32);
        replace_full(c,m_id,32,state);

        sonic_encrypt_512_procrastinate(state,state);

        clen -= 32;
        m_id += 32;

    }
    if(clen>=1){

        //printf("len clen %lld \n",clen);
        cur_absorbe[0] = 0;
        cur_absorbe[1] = 0;
        cur_absorbe[2] = 0;
        cur_absorbe[3] = 0;

        for(int i=0;i<clen;i++){
            cur_absorbe[i>>3] ^= (uint64_t)c[m_id+i] << ((7-(i & 7))<<3);
        }

        add_byte(state,cur_absorbe,clen,state);
        extract_ciphertext(state,m,m_id,clen);
        replace(cur_absorbe,clen,state);

    }
    else
    if(clen==0){
        cur_absorbe[0] = (uint64_t)0x80 << 56;
        add_byte(state,cur_absorbe,1,state);
    }

    //finalization

    add_key_to_state(state,key,4);
    sonic_encrypt_512_procrastinate(state,state);
    add_key_to_state(state,key,4);

    unsigned char tag[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    for(int i=0;i<16;i++)
        tag[i] = 0;
    extract_ciphertext(state+6,tag,0,16);

    int correct = 0;
    for(int i=0;i<16;i++){
        if((tag[i]!=c[(*mlen)+i])){ 
            correct = 1;
        }
    }

    if(correct==1) return -1;
    else return 0;
}

