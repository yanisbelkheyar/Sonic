
#take a 8 bit constant and map it to a size bit word with bit at position i*w/8
def f_512(cc,size):
    constant= [0,0,0,0]
    idx = size//8
    for i in range(2):
        constant[0] |= ((cc>>i) & 1)<<(64-i*idx-1)
        constant[1] |= ((cc>>(i+2)) & 1)<<(64-i*idx-1)
        constant[2] |= ((cc>>(i+4)) & 1)<<(64-i*idx-1)
        constant[3] |= ((cc>>(i+6)) & 1)<<(64-i*idx-1)
    print("{",hex(constant[0]),",",hex(constant[1]),",",hex(constant[2]),",",hex(constant[3]),end="}, .size_64 = 4};\n")


def f_256(cc,size):
    constant = [0,0]
    idx = size//8
    for i in range(4):
        constant[0] |= ((cc>>i) & 1)<<(64-i*idx-1)
        constant[1] |= ((cc>>(i+4)) & 1)<<(64-i*idx-1)
    print("{",hex(constant[0]),",",hex(constant[1]),end="}, .size_64 = 2};\n")



list_cc=[0xf9,0x47,0xeb,0x37,0x69,0x3b,0x49,0x3a,0xb0,0x7d,0x5b,0x4a,0x32,0x71,0x7b,0x4b,0xcb,0x36,0x90,0x7c,0xa2,0x0d,0xd9,0x46,0x12,0x70,0x82,0x0c,0x20,0x01]

for i in range(len(list_cc)):
    f_256(list_cc[i],128)

print()

for i in range(len(list_cc)):
    f_512(list_cc[i],256)
