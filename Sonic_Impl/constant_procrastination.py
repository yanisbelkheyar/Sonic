import sys
"""
def constante(value,nbr_round,size):
    a = [(value*(111**i))%size for i in range(nbr_round)]
    print('int shift_'+str(value)+'_'+str(size)+'['+str(nbr_round)+'] = {',end='')
    for i in range(len(a)):
        if(i<len(a)-1):
            print(str(a[i])+',',end='')
        else:
            print(str(a[i])+'};')

size = int(sys.argv[1])
nbr_round = int(sys.argv[2])
for i in range(len(sys.argv)-3):
    constante(int(sys.argv[i+3]),nbr_round,size)

"""



#take a 8 bit constant and map it to a size bit word with bit at position i*w/8
def f_512(cc,size,nbr_round):
    constant= [0,0,0,0]
    idx = size//8
    for i in range(2):
        constant[0] |= ((cc>>i) & 1)<<(64-i*idx-1)
        constant[1] |= ((cc>>(i+2)) & 1)<<(64-i*idx-1)
        constant[2] |= ((cc>>(i+4)) & 1)<<(64-i*idx-1)
        constant[3] |= ((cc>>(i+6)) & 1)<<(64-i*idx-1)
    #print("{",hex(constant[0]),",",hex(constant[1]),",",hex(constant[2]),",",hex(constant[3]),end="}, .size_64 = 4};\n")

    n_constant= [0,0,0,0]
    #apply the multiplicative shuffle to the power the round number
    #print(hex(cc))
    for i in range(4):
        for j in range(64):
            id = (i*64+j)*(15**(16-nbr_round-1)) % size
            #print(i,"index previous, ",id," index next, print mull val = ",111**(20-nbr_round-1 )%128)
            n_constant[i] |= (constant[id//64]>>((size-id-1)%64)&1)<<((size-j-1)%64)

    print("{",hex(n_constant[0]),",",hex(n_constant[1]),",",hex(n_constant[2]),",",hex(n_constant[3]),end="}, .size_64 = 4};\n")


def f_256(cc,size,nbr_round):
    constant = [0,0]
    idx = size//8
    #print(bin(cc))
    for i in range(4):
        constant[0] |= ((cc>>i) & 1)<<(64-i*idx-1)
        constant[1] |= ((cc>>(i+4)) & 1)<<(64-i*idx-1)

    #apply the multiplicative shuffle to the power the round number
    n_constant = [0,0] 
    #print(hex(cc))
    #print(bin(constant[0]),bin(constant[1]))

    for i in range(2):
        for j in range(64):
            id = (i*64+j)*(15**(20-nbr_round-1)) % size
            #print(i,"index previous, ",id," index next, print mull val = ",111**(20-nbr_round-1 )%128)
            n_constant[i] |= (constant[id//64]>>((size-id-1)%64)&1)<<((size-j-1)%64)
            #if((constant[id//64]>>((128-id-1)%64)&1)==1):
            #    print(id,"index previous, ",j," index next, print mull val = ",(15**(20-nbr_round-1))%size)

    #print(bin(n_constant[0]),bin(n_constant[1]))
    print("{",hex(n_constant[0]),",",hex(n_constant[1]),end="}, .size_64 = 2};\n")



list_cc=[0xf9,0x47,0xeb,0x37,0x69,0x3b,0x49,0x3a,0xb0,0x7d,0x5b,0x4a,0x32,0x71,0x7b,0x4b,0xcb,0x36,0x90,0x7c,0xa2,0x0d,0xd9,0x46,0x12,0x70,0x82,0x0c,0x20,0x01]

#"""
for i in range(20):
    f_256(list_cc[i],128,i)
#"""
"""
for i in range(16):
    f_512(list_cc[i],256,i)
"""
