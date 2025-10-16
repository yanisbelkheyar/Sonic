def new_pos(shift,index):
    return (abs((index-shift)//4),(index-shift)%4)

def rot(shift):
    return (new_pos(shift,0),new_pos(shift,1),new_pos(shift,2),new_pos(shift,3))

#old rotation values
list_shift1 = [1 ,239 ,33 ,207 ,65 ,175 ,97 ,143 ,129 ,111 ,161 ,79 ,193 ,47 ,225 ,15 ,1]
list_shift7 = [7 ,137 ,231 ,169 ,199 ,201 ,167 ,233 ,135 ,9 ,103 ,41 ,71 ,73 ,39 ,105 ,7]
list_shift32 = [32 ,224 ,32 ,224 ,32 ,224 ,32 ,224 ,32 ,224 ,32 ,224 ,32 ,224 ,32 ,224 ,32]
list_shift5 = [5 ,171 ,165 ,11 ,69 ,107 ,229 ,203 ,133 ,43 ,37 ,139 ,197 ,235 ,101 ,75 ,5]

#new rotation values
shift_0_256 = [0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ]

shift_5_256 = [5 ,243 ,181 ,99 ,197 ,211 ,213 ,67 ,229 ,179 ,245 ,35 ,5 ]  
shift_1_256 = [1 ,151 ,241 ,71 ,193 ,247 ,145 ,167 ,97 ,87 ,49 ,7 ,1 ]  
shift_3_256 = [3 ,197 ,211 ,213 ,67 ,229 ,179 ,245 ,35 ,5 ,147 ,21 ,3 ]  
shift_20_256 = [20 ,204 ,212 ,140 ,20 ,76 ,84 ,12 ,148 ,204 ,212 ,140 ,20 ] 



c_256_f9_procr = [ 0x8000000080000000 , 0x8000000080000000 , 0x8000000080000000 , 0x0]
c_256_47_procr = [ 0x8000000080000000 , 0x8000000000000000 , 0x0 , 0x8000000000000000]
c_256_eb_procr = [ 0x8000000080000000 , 0x8000000080000000 , 0x80000000 , 0x80000000]
c_256_37_procr = [ 0x8000000080000000 , 0x8000000000000000 , 0x8000000080000000 , 0x0]
c_256_69_procr = [ 0x8000000000000000 , 0x8000000080000000 , 0x80000000 , 0x0]
c_256_3b_procr = [ 0x8000000080000000 , 0x80000000 , 0x8000000080000000 , 0x0]
c_256_49_procr = [ 0x8000000000000000 , 0x8000000000000000 , 0x80000000 , 0x0]
c_256_3a_procr = [ 0x80000000 , 0x80000000 , 0x8000000080000000 , 0x0]
c_256_b0_procr = [ 0x80000000 , 0x80000000 , 0x8000000000000000 , 0x0]
c_256_7d_procr = [ 0x8000000000000000 , 0x8000000080000000 , 0x8000000080000000 , 0x8000000000000000]
c_256_5b_procr = [ 0x8000000000000000 , 0x8000000000000000 , 0x8000000080000000 , 0x80000000]
c_256_4a_procr = [ 0x80000000 , 0x80000000 , 0x0 , 0x8000000000000000]

list_constant = [c_256_f9_procr,c_256_47_procr,c_256_eb_procr,c_256_37_procr,c_256_69_procr,c_256_3b_procr,c_256_49_procr,c_256_3a_procr,c_256_b0_procr,c_256_7d_procr,c_256_5b_procr,c_256_4a_procr]

list_shift = [shift_5_256,shift_0_256,shift_1_256,shift_3_256,shift_20_256]


def print_rot(list_shift):
    idx = 0
    for i in reversed(list_shift):
        print(i)
        r = rot(i)
        if(idx%2==0):
            for j in range(4):
                print("ror_help_inter(left.data_64["+str(r[j][1])+"],"+str(r[j][0])+");")
        else:
            for j in range(4):
                print("ror_help_inter(right.data_64["+str(r[j][1])+"],"+str(r[j][0])+");")
        idx+=1

def generat_rot(list_shift):
    r = []
    for i in reversed(list_shift):
        r.append(rot(i))
    return r

list_rot = [generat_rot(i) for i in list_shift]

        
def generate_round(round_number):
    #for the left part round 1
    #right->data_64[0] ^= (ror_help_inter(left->data_64[3],1) & left->data_64[0]) ^ ror_help_inter(left->data_64[3],2);
    #right->data_64[1] ^= (ror_help_inter(left->data_64[0],0) & left->data_64[1]) ^ ror_help_inter(left->data_64[0],1);
    #right->data_64[2] ^= (ror_help_inter(left->data_64[1],0) & left->data_64[2]) ^ ror_help_inter(left->data_64[1],1);
    #right->data_64[3] ^= (ror_help_inter(left->data_64[2],0) & left->data_64[3]) ^ ror_help_inter(left->data_64[2],1);

    if round_number%2==0 :
        print("right->data_64[0] ^= ("+"ror_help_inter(left->data_64["+str(list_rot[2][round_number][0][1])+"],"+str(list_rot[2][round_number][0][0])+") &  left->data_64[0]) ^ ror_help_inter(left->data_64["+str(list_rot[0][round_number][0][1])+"],"+str(list_rot[0][round_number][0][0])+");")
        print("right->data_64[1] ^= ("+"ror_help_inter(left->data_64["+str(list_rot[2][round_number][1][1])+"],"+str(list_rot[2][round_number][1][0])+") &  left->data_64[1]) ^ ror_help_inter(left->data_64["+str(list_rot[0][round_number][1][1])+"],"+str(list_rot[0][round_number][1][0])+");")
        print("right->data_64[2] ^= ("+"ror_help_inter(left->data_64["+str(list_rot[2][round_number][2][1])+"],"+str(list_rot[2][round_number][2][0])+") &  left->data_64[2]) ^ ror_help_inter(left->data_64["+str(list_rot[0][round_number][2][1])+"],"+str(list_rot[0][round_number][2][0])+");")
        print("right->data_64[3] ^= ("+"ror_help_inter(left->data_64["+str(list_rot[2][round_number][3][1])+"],"+str(list_rot[2][round_number][3][0])+") &  left->data_64[3]) ^ ror_help_inter(left->data_64["+str(list_rot[0][round_number][3][1])+"],"+str(list_rot[0][round_number][3][0])+");")

    #left->data_64[0] ^= ror_help_inter(left->data_64[1],2) ^ ror_help_inter(left->data_64[0],8) ^ 0x8000000080000000;
    #left->data_64[1] ^= ror_help_inter(left->data_64[2],2) ^ ror_help_inter(left->data_64[1],8) ^ 0x80000000;
    #left->data_64[1] ^= ror_help_inter(left->data_64[3],2) ^ ror_help_inter(left->data_64[2],8) ^ 0x0;
    #left->data_64[3] ^= ror_help_inter(left->data_64[0],1) ^ ror_help_inter(left->data_64[3],8) ^ 0x8000000000000000;
        print()

        print("left->data_64[0] ^= "+"ror_help_inter(left->data_64["+str(list_rot[3][round_number][0][1])+"],"+str(list_rot[3][round_number][0][0])+") ^ ror_help_inter(left->data_64["+str(list_rot[4][round_number][0][1])+"],"+str(list_rot[4][round_number][0][0])+") ^ "+str(hex(list_constant[11-round_number][0]))+";")
        print("left->data_64[1] ^= "+"ror_help_inter(left->data_64["+str(list_rot[3][round_number][1][1])+"],"+str(list_rot[3][round_number][1][0])+") ^ ror_help_inter(left->data_64["+str(list_rot[4][round_number][1][1])+"],"+str(list_rot[4][round_number][1][0])+") ^ "+str(hex(list_constant[11-round_number][1]))+";")
        print("left->data_64[2] ^= "+"ror_help_inter(left->data_64["+str(list_rot[3][round_number][2][1])+"],"+str(list_rot[3][round_number][2][0])+") ^ ror_help_inter(left->data_64["+str(list_rot[4][round_number][2][1])+"],"+str(list_rot[4][round_number][2][0])+") ^ "+str(hex(list_constant[11-round_number][2]))+";")
        print("left->data_64[3] ^= "+"ror_help_inter(left->data_64["+str(list_rot[3][round_number][3][1])+"],"+str(list_rot[3][round_number][3][0])+") ^ ror_help_inter(left->data_64["+str(list_rot[4][round_number][3][1])+"],"+str(list_rot[4][round_number][3][0])+") ^ "+str(hex(list_constant[11-round_number][3]))+";")

        print()
    #left->data_64[0] ^= (ror_help_inter(right->data_64[1],4) & right->data_64[0]) ^ ror_help_inter(right->data_64[1],19);  
    #left->data_64[1] ^= (ror_help_inter(right->data_64[2],4) & right->data_64[1]) ^ ror_help_inter(right->data_64[2],19); 
    #left->data_64[2] ^= (ror_help_inter(right->data_64[3],4) & right->data_64[2]) ^ ror_help_inter(right->data_64[3],19); 
    #left->data_64[3] ^= (ror_help_inter(right->data_64[0],3) & right->data_64[3]) ^ ror_help_inter(right->data_64[0],18); 
    elif round_number %2==1:
        print("left->data_64[0] ^= ("+"ror_help_inter(right->data_64["+str(list_rot[1][round_number][0][1])+"],"+str(list_rot[1][round_number][0][0])+") &  right->data_64[0]) ^ ror_help_inter(right->data_64["+str(list_rot[0][round_number][0][1])+"],"+str(list_rot[0][round_number][0][0])+");")
        print("left->data_64[1] ^= ("+"ror_help_inter(right->data_64["+str(list_rot[1][round_number][1][1])+"],"+str(list_rot[1][round_number][1][0])+") &  right->data_64[1]) ^ ror_help_inter(right->data_64["+str(list_rot[0][round_number][1][1])+"],"+str(list_rot[0][round_number][1][0])+");")
        print("left->data_64[2] ^= ("+"ror_help_inter(right->data_64["+str(list_rot[1][round_number][2][1])+"],"+str(list_rot[1][round_number][2][0])+") &  right->data_64[2]) ^ ror_help_inter(right->data_64["+str(list_rot[0][round_number][2][1])+"],"+str(list_rot[0][round_number][2][0])+");")
        print("left->data_64[3] ^= ("+"ror_help_inter(right->data_64["+str(list_rot[1][round_number][3][1])+"],"+str(list_rot[1][round_number][3][0])+") &  right->data_64[3]) ^ ror_help_inter(right->data_64["+str(list_rot[0][round_number][3][1])+"],"+str(list_rot[0][round_number][3][0])+");")
    
        print()
    #right->data_64[0] ^= ror_help_inter(right->data_64[3],27) ^ ror_help_inter(right->data_64[0],56) ^ 0x8000000000000000;
    #right->data_64[1] ^= ror_help_inter(right->data_64[0],26) ^ ror_help_inter(right->data_64[1],56) ^ 0x8000000080000000;
    #right->data_64[2] ^= ror_help_inter(right->data_64[1],26) ^ ror_help_inter(right->data_64[2],56) ^ 0x8000000080000000;
    #right->data_64[3] ^= ror_help_inter(right->data_64[2],26) ^ ror_help_inter(right->data_64[3],56) ^ 0x80000000;
        print("right->data_64[0] ^= "+"ror_help_inter(right->data_64["+str(list_rot[3][round_number][0][1])+"],"+str(list_rot[3][round_number][0][0])+") ^ ror_help_inter(right->data_64["+str(list_rot[4][round_number][0][1])+"],"+str(list_rot[4][round_number][0][0])+") ^ "+str(hex(list_constant[11-round_number][0]))+";")
        print("right->data_64[1] ^= "+"ror_help_inter(right->data_64["+str(list_rot[3][round_number][1][1])+"],"+str(list_rot[3][round_number][1][0])+") ^ ror_help_inter(right->data_64["+str(list_rot[4][round_number][1][1])+"],"+str(list_rot[4][round_number][1][0])+") ^ "+str(hex(list_constant[11-round_number][1]))+";")
        print("right->data_64[2] ^= "+"ror_help_inter(right->data_64["+str(list_rot[3][round_number][2][1])+"],"+str(list_rot[3][round_number][2][0])+") ^ ror_help_inter(right->data_64["+str(list_rot[4][round_number][2][1])+"],"+str(list_rot[4][round_number][2][0])+") ^ "+str(hex(list_constant[11-round_number][2]))+";")
        print("right->data_64[3] ^= "+"ror_help_inter(right->data_64["+str(list_rot[3][round_number][3][1])+"],"+str(list_rot[3][round_number][3][0])+") ^ ror_help_inter(right->data_64["+str(list_rot[4][round_number][3][1])+"],"+str(list_rot[4][round_number][3][0])+") ^ "+str(hex(list_constant[11-round_number][3]))+";")
        print()

for i in range(12):
    generate_round(i)

#print_rot(list_shift32)
#
#for i in list_shift:
#    print_rot(i)
#    print()