### In this file we define a python code to describe the family of permutation Sonic
### This code is not made to be use as an efficient implementation but rather as an easy and accessible testing environment

import numpy as np 
from bitarray import bitarray
from bitarray.util import hex2ba
import binascii


###################################################################
#                        Generic variables                        #
###################################################################

SIZE = 256
H_SIZE = SIZE//2
NBR_ROUND = 20

###################################################################
#                       Auxiliary functions                       #
###################################################################

## We represent words as bitarray with bit 0 on the left
def printbitarray(a):
    aa = bitarray(a,endian='big')
    print(aa[0:len(aa)//2].tobytes().hex(), aa[len(a)//2:len(aa)].tobytes().hex())

## compact representation of round constants
round_constants = []
list_cc=[0xf9,0x47,0xeb,0x37,0x69,0x3b,0x49,0x3a,0xb0,0x7d,0x5b,0x4a,0x32,0x71,0x7b,0x4b,0xcb,0x36,0x90,0x7c,0xa2,0x0d,0xd9,0x46]

## function to generate a round constant starting from its compact representation
def compute_rc(cc):
    rc = bitarray(H_SIZE, endian='little')
    idx = H_SIZE//8
    for i in range(8):
        rc[i*idx] = ((cc>>i) & 1)
    #print("0x{:02x}".format(cc), printbitarray(rc))
    return rc

## function to generate the round constants given a list with their compact representations
def compute_round_constants(list_cc):
    global round_constants
    for i in range(len(list_cc)):
        round_constants = round_constants + [compute_rc(list_cc[i])]
    return round_constants

###################################################################
#                      Permutation functions                      #
###################################################################

## circular shift
def circular_shift(word, shift_val):
    return ((word >> (H_SIZE - (shift_val % H_SIZE))) | (word << (shift_val % H_SIZE)))

## multiplicative shuffle
def multiplicative_shuffle(word,mul_val):
    a = bitarray(H_SIZE, endian='little')
    for i in range(H_SIZE):
        # print(i,(i*mul_val)%H_SIZE)
        # print(word[(i*mul_val)%H_SIZE])
        a[i] = word[(i*mul_val)%H_SIZE]
    return a

## constant addition
def constant_add(word,round_nbr):
    return (word ^ round_constants[round_nbr])

## Round function
def Sonic_round(x,y,round_nbr):
    # print("rc", hex(list_cc[round_nbr]), bin(list_cc[round_nbr]))
    # print(round_constants[round_nbr])
    # printbitarray(round_constants[round_nbr])
    ## z = x AND τ(x)
    z = x & circular_shift(x,1)
    ## y = y XOR τ^5(x) XOR z
    y = y ^ circular_shift(x,5) ^ z
    #print("right branch before PI");
    #printbitarray(y) #print(y) #
    ## y = π_15(y)
    y = multiplicative_shuffle(y,15)
    # print("right branch after PI");
    # printbitarray(y) #print(y) #
    ## x = x XOR τ^7(x) XOR τ^32(x)
    x = x ^ circular_shift(x,7) ^ circular_shift(x,32)
    #print("left branch before rc");
    #printbitarray(x) #print(x) #
    ## x = π_15(x XOR rc)
    temp = constant_add(x,round_nbr)
    #print("left branch before PI");
    #printbitarray(temp) # print(temp) #
    x = multiplicative_shuffle(temp,15)
    ## (x, y) = (y, x)
    # print("left branch after PI");
    # printbitarray(x) # print(x) #
    return (y,x)

## Permutation
def Sonic256_permutation(data_in):
    word_left = bitarray(data_in[0:H_SIZE], endian='little')
    word_right = bitarray(data_in[H_SIZE:SIZE], endian='little')
    for i in range(NBR_ROUND):
        # print("round",i)
        word_left,word_right = Sonic_round(word_left,word_right,NBR_ROUND-1-i)
        # print("round output");
        # printbitarray(word_left)
        # printbitarray(word_right)
        # print()
    
    # correction
    word_left = multiplicative_shuffle(word_left, 65)
    word_right = multiplicative_shuffle(word_right, 65)
    
    # print("after final shuffle");
    # printbitarray(word_left)
    # printbitarray(word_right)
    return word_left+word_right

###################################################################
#                             SonicBoom                           #
###################################################################

## SonicBoom
def SonicBoom(data_in,key):
    # xor input with key
    perm_in = data_in ^ key;
    # apply permutation
    perm_out = Sonic256_permutation(perm_in);
    # xor permutation output with the key
    data_out = perm_out ^ key;
    return data_out

###################################################################
#                               SoniK                             #
###################################################################

# TODO




###################################################################
#                               Tests                             #
###################################################################

# test the permutation Sonic256 against Known Answer Tests
def test_sonic256():
    print("##### TEST SONIC 256 #####")
    
    # redefine global variables
    global SIZE, H_SIZE, NBR_ROUND, rounround_constants
    SIZE = 256
    H_SIZE = SIZE//2
    NBR_ROUND = 20
    
    # generate round constants for Sonic256
    round_constants = compute_round_constants(list_cc)

    ## TEST 1: all 0 data_in
    print("TEST 1")
    data_in_string = "0000000000000000000000000000000000000000000000000000000000000000"
    expected_output_string = "f24671dbd325467c2c7754cb945564af640b351978d01a6cfa10ea8b725a0c59"
    
    data_in = bitarray(format(int(data_in_string,16), '0256b'), endian='little')
    expected_output = bitarray(format(int(expected_output_string,16), '0256b'), endian='little')
    data_out = Sonic256_permutation(data_in)
    
    if(expected_output == data_out):
        print("PASS")
    else:
        print("FAIL")
        print("data_in is")
        print(data_in)
        printbitarray(data_in)
        print("output is")
        print(data_out)
        printbitarray(data_out) 
        print("expected output is")
        print(expected_output)
        printbitarray(expected_output) 
    
    ## TEST 2:
    print("TEST 2")
    data_in_string = "327b23c66b8b456766334873643c986919495cff74b0dc51625558ec2ae8944a"
    expected_output_string = "9e5658c4ffde1b5fa9391c1aded2eb46cb0eb42dc4692c0bb12aff450382e391"
    
    data_in = bitarray(format(int(data_in_string,16), '0256b'), endian='little')
    expected_output = bitarray(format(int(expected_output_string,16), '0256b'), endian='little')
    data_out = Sonic256_permutation(data_in)
    
    if(expected_output == data_out):
        print("PASS")
    else:
        print("FAIL")
        print("data_in is")
        print(data_in)
        printbitarray(data_in)
        print("output is")
        print(data_out)
        printbitarray(data_out) 
        print("expected output is")
        print(expected_output)
        printbitarray(expected_output) 
    
    ## TEST 3: 
    print("TEST 3")
    data_in_string = "46e87ccd238e1f29507ed7ab3d1b58ba41b71efb2eb141f27545e14679e2a9e3"
    expected_output_string = "9ec7536bf53af8146171182ef556410711cb062e4b1f520b3b9c13811f3e2012"
    
    data_in = bitarray(format(int(data_in_string,16), '0256b'), endian='little')
    expected_output = bitarray(format(int(expected_output_string,16), '0256b'), endian='little')
    data_out = Sonic256_permutation(data_in)
    
    if(expected_output == data_out):
        print("PASS")
    else:
        print("FAIL")
        print("data_in is")
        print(data_in)
        printbitarray(data_in)
        print("output is")
        print(data_out)
        printbitarray(data_out) 
        print("expected output is")
        print(expected_output)
        printbitarray(expected_output) 
    
    ## TEST 4: 
    print("TEST 4")
    data_in_string = "5bd062c2515f007c4db127f8122008541f16e9e80216231b66ef438d1190cde7"
    expected_output_string = "38c3c7b43329c3d436327d76ca0fd12f89b022d7b058f938402d4da122fa06fb"
    
    data_in = bitarray(format(int(data_in_string,16), '0256b'), endian='little')
    expected_output = bitarray(format(int(expected_output_string,16), '0256b'), endian='little')
    data_out = Sonic256_permutation(data_in)
    
    if(expected_output == data_out):
        print("PASS")
    else:
        print("FAIL")
        print("data_in is")
        print(data_in)
        printbitarray(data_in)
        print("output is")
        print(data_out)
        printbitarray(data_out) 
        print("expected output is")
        print(expected_output)
        printbitarray(expected_output) 

def test_sonicBoom():
    print("##### TEST SONICBOOM #####")
    
    # redefine global variables
    global SIZE, H_SIZE, NBR_ROUND, rounround_constants
    SIZE = 256
    H_SIZE = SIZE//2
    NBR_ROUND = 20
    
    # generate round constants for Sonic256
    round_constants = compute_round_constants(list_cc)

    ## TEST 1: all 0 data_in and key
    print("TEST 1")
    data_in_string = "0000000000000000000000000000000000000000000000000000000000000000"
    key_string = "0000000000000000000000000000000000000000000000000000000000000000"
    expected_output_string = "f24671dbd325467c2c7754cb945564af640b351978d01a6cfa10ea8b725a0c59"
    
    data_in = bitarray(format(int(data_in_string,16), '0256b'), endian='little')
    key = bitarray(format(int(key_string,16), '0256b'), endian='little')
    expected_output = bitarray(format(int(expected_output_string,16), '0256b'), endian='little')
    data_out = SonicBoom(data_in,key)
    
    if(expected_output == data_out):
        print("PASS")
    else:
        print("FAIL")
        print("data_in is")
        print(data_in)
        printbitarray(data_in)
        print("output is")
        print(data_out)
        printbitarray(data_out) 
        print("expected output is")
        print(expected_output)
        printbitarray(expected_output) 
    
    ## TEST 2: random
    print("TEST 2")
    data_in_string = "327b23c66b8b456766334873643c986919495cff74b0dc51625558ec2ae8944a"
    key_string = "9ec7536bf53af8146171182ef556410711cb062e4b1f520b3b9c13811f3e2012"
    expected_output_string = "1e6bbee29f4e157cf14a648b75c7200d040e8354606e34f783f8af156adaa6e9"
    
    data_in = bitarray(format(int(data_in_string,16), '0256b'), endian='little')
    key = bitarray(format(int(key_string,16), '0256b'), endian='little')
    expected_output = bitarray(format(int(expected_output_string,16), '0256b'), endian='little')
    data_out = SonicBoom(data_in,key)
    
    if(expected_output == data_out):
        print("PASS")
    else:
        print("FAIL")
        print("data_in is")
        print(data_in)
        printbitarray(data_in)
        print("output is")
        print(data_out)
        printbitarray(data_out) 
        print("expected output is")
        print(expected_output)
        printbitarray(expected_output) 




if __name__ == "__main__":
    
    #test_sonic256();
    test_sonicBoom();
    