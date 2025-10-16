### In this file we define a python code to describe the family of permutation Sonic
### This code is not made to be use as an efficient implementation but rather as an easy and accessible testing environment

import numpy as np
from bitarray import bitarray
from bitarray.util import hex2ba
import binascii


###################################################################
#                        Generic variables                        #
###################################################################

SIZE = 512
H_SIZE = SIZE//2
NBR_ROUND = 12

###################################################################
#                       Auxiliary functions                       #
###################################################################

## We represent words as bitarray with bit 0 on the left
def printbitarray(a):
    aa = bitarray(a,endian='big')
    print(aa[0:len(aa)//2].tobytes().hex(), aa[len(a)//2:len(aa)].tobytes().hex())

## compact representation of round constants
round_constants = []
list_cc=[0xf9,0x47,0xeb,0x37,0x69,0x3b,0x49,0x3a,0xb0,0x7d,0x5b,0x4a]

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
    y = multiplicative_shuffle(y,7)
    # print("right branch after PI");
    # printbitarray(y) #print(y) #
    ## x = x XOR τ^7(x) XOR τ^32(x)
    x = x ^ circular_shift(x,3) ^ circular_shift(x,20)
    #print("left branch before rc");
    #printbitarray(x) #print(x) #
    ## x = π_15(x XOR rc)
    temp = constant_add(x,round_nbr)
    #print("left branch before PI");
    #printbitarray(temp) # print(temp) #
    x = multiplicative_shuffle(temp,7)
    ## (x, y) = (y, x)
    # print("after PI");
    # printbitarray(x)
    # printbitarray(y)
    #print(x) #
    return (y,x)

## Permutation
def Sonic512_permutation(data_in):
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
    word_left = multiplicative_shuffle(word_left, 225)
    word_right = multiplicative_shuffle(word_right, 225)

    # print("after final shuffle");
    # printbitarray(word_left)
    # printbitarray(word_right)
    return word_left+word_right


###################################################################
#                               Tests                             #
###################################################################

# test the permutation Sonic256 against Known Answer Tests
def test_sonic512():
    print("##### TEST SONIC 256 #####")

    # redefine global variables
    global SIZE, H_SIZE, NBR_ROUND, rounround_constants
    SIZE = 512
    H_SIZE = SIZE//2
    NBR_ROUND = 12

    # generate round constants for Sonic256
    round_constants = compute_round_constants(list_cc)

    # TEST 1: all 0 data_in
    print("TEST 1")
    data_in_string = "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"
    expected_output_string = "b924b8dda3d5d25cea0061368f71f277d3b5b09e57c72cc3b81533f70185f78d6c5e16b3acdddfda66798489e6c27955c5801f640df9ce1a488ddd8b00865fdf"

    data_in = bitarray(format(int(data_in_string,16), '0512b'), endian='little')
    expected_output = bitarray(format(int(expected_output_string,16), '0512b'), endian='little')
    data_out = Sonic512_permutation(data_in)

    if(expected_output == data_out):
        print("PASS")
    else:
        print("FAIL")
        print("data_in is")
        #print(data_in)
        printbitarray(data_in)
        print("output is")
        #print(data_out)
        printbitarray(data_out)
        print("expected output is")
        #print(expected_output)
        printbitarray(expected_output)

    ## TEST 2:
    print("TEST 2")
    data_in_string = "00000000000000000000000000000000baabf2fbe3467cc254f81be8e78d765a2e63339fc99a66320db73158a35a255d051758e95ed4abb2cdc69bb454110e82"
    expected_output_string = "7b394465677f9f4c5d465f63d18dde16223db893fcb36fbfc55506f59f00c67d77eb0a262dc454930c2fdde3476344c2f79d19a4db4f8a864733730731777034"

    data_in = bitarray(format(int(data_in_string,16), '0512b'), endian='little')
    expected_output = bitarray(format(int(expected_output_string,16), '0512b'), endian='little')
    data_out = Sonic512_permutation(data_in)

    if(expected_output == data_out):
        print("PASS")
    else:
        print("FAIL")
        print("data_in is")
        #print(data_in)
        printbitarray(data_in)
        print("output is")
        #print(data_out)
        printbitarray(data_out)
        print("expected output is")
        #print(expected_output)
        printbitarray(expected_output)

if __name__ == "__main__":

    test_sonic512();
