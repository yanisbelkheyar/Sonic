### In this file we define a python code to describe the familly of permutation Sonic
### This code is not made to be use as an efficient implementation but rather as an easy and accesible testing environment


## We represent words (half of the state) as numpy array

import numpy as np 
import sys
import random #for testing


SIZE = int(sys.argv[1])
H_SIZE = SIZE//2
if(SIZE==256):
    NBR_ROUND = 24
else:
    NBR_ROUND = 16


round_constante = np.array([[0]*H_SIZE]*NBR_ROUND,dtype=bool)

## circular shift
# take as input a nupy arrya representing a word and shift it circularly to the right
def circular_shift(word, shift_val):
    return np.array([word[(i+shift_val)%H_SIZE] for i in range(H_SIZE)],dtype=bool)

## Step function 

# non linear function
#take numpy array representing one half of the state and apply the non-linear transformation consisting in one and, plus one xor
def non_linear(word):
    w_shifted_1 = circular_shift(word,1)
    w_shifted_5 = circular_shift(word,5)
    res = np.bitwise_and(w_shifted_1,word)
    return np.bitwise_xor(res,w_shifted_5)

# mixing layer
def mixing_layer(word):
    w_shifted_7 = circular_shift(word,7)
    w_shifted_32 = circular_shift(word,32)
    res = np.bitwise_xor(w_shifted_32,w_shifted_7)
    return np.bitwise_xor(word,res)

def mixing_layer_inv_256(word):

    w_shifted_7 = circular_shift(word,7)
    w_shifted_32 = circular_shift(word,32)
    res = np.bitwise_xor(w_shifted_32,w_shifted_7)
    w_shifted_14 = circular_shift(word,14)
    res = np.bitwise_xor(res,w_shifted_14)
    w_shifted_64 = circular_shift(word,64)
    res = np.bitwise_xor(res,w_shifted_64)
    w_shifted_100 = circular_shift(word,100)    
    return np.bitwise_xor(res,w_shifted_100)

def mixing_layer_inv_512(word):
    
    w_shifted_7 = circular_shift(word,7)
    w_shifted_32 = circular_shift(word,32)
    res = np.bitwise_xor(w_shifted_32,w_shifted_7)
    w_shifted_14 = circular_shift(word,14)
    res = np.bitwise_xor(res,w_shifted_14)
    w_shifted_64 = circular_shift(word,64)
    res = np.bitwise_xor(res,w_shifted_64)
    w_shifted_28 = circular_shift(word,28)
    res = np.bitwise_xor(res,w_shifted_28)
    w_shifted_128 = circular_shift(word,128)
    res = np.bitwise_xor(res,w_shifted_128)
    w_shifted_200 = circular_shift(word,200)
    return np.bitwise_xor(res,w_shifted_200)


# multiplicativ shuffle
def multiplicative_shuffle(word,mul_val):
    return np.array([word[(i*mul_val) % H_SIZE] for i in range(H_SIZE)],dtype=bool)

# constant addition
def constant_add(word,round_nbr):
    return np.bitwise_xor(round_constante[round_nbr],word)

## Round function
def Sonic_round(word_left,word_right,round_nbr):
    word_right = multiplicative_shuffle(np.bitwise_xor(word_right,non_linear(word_left)),15)
    word_left = multiplicative_shuffle(constant_add(mixing_layer(word_left),round_nbr),15)

    return (word_right,word_left)

def Sonic_inv_round_256(word_left,word_right,round_nbr):
    
    word_right = multiplicative_shuffle(np.bitwise_xor(word_right,non_linear(word_left)),111)
    word_left = multiplicative_shuffle(constant_add(mixing_layer_inv_256(word_left),NBR_ROUND-round_nbr-1),111)

    return (word_right,word_left)   

def Sonic_inv_round_512(word_left,word_right,round_nbr):
        
    word_right = multiplicative_shuffle(np.bitwise_xor(word_right,non_linear(word_left)),239)
    word_left = multiplicative_shuffle(constant_add(mixing_layer_inv_512(word_left),NBR_ROUND-round_nbr-1),239)

    return (word_right,word_left)   


## we show an example for an even-masour construction with 24 round of the round function

def Sonic_iterated(word_left,word_right):
    for i in range(NBR_ROUND):
        word_left,word_right = Sonic_round(word_left,word_right,i)

    return (word_left,word_right)


def Sonic_iterated_inv(word_left,word_right):
    if(SIZE==256):
        for i in range(NBR_ROUND):
            word_left,word_right = Sonic_inv_round_256(word_left,word_right,i)
        return (word_left,word_right)
    else:
        for i in range(NBR_ROUND):
            word_left,word_right = Sonic_inv_round_512(word_left,word_right,i)
        return (word_left,word_right)


def print_hex(tab):
    val = 0
    for i in range(len(tab)):
        if(tab[i]):
            val += 2**i
    print(hex(val),end=' ')


right,left = [random.randint(0,1) for i in range(H_SIZE)],[random.randint(0,1) for i in range(H_SIZE)]

print('input')
print_hex(right)
print_hex(left)
output_right,output_left = Sonic_iterated(right,left)
print('\noutput')
print_hex(output_right)
print_hex(output_left)
input_right,input_left = Sonic_iterated_inv(output_right,output_left)
print('\ninput')
print_hex(input_right)
print_hex(input_left)