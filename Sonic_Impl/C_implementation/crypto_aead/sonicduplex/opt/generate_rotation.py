def new_pos(shift,index):
    return (abs((index-shift)//4),(index-shift)%4)

def rot(shift):
    return (new_pos(shift,0),new_pos(shift,1),new_pos(shift,2),new_pos(shift,3))


list_shift1 = [1 ,239 ,33 ,207 ,65 ,175 ,97 ,143 ,129 ,111 ,161 ,79 ,193 ,47 ,225 ,15 ,1]
list_shift7 = [7 ,137 ,231 ,169 ,199 ,201 ,167 ,233 ,135 ,9 ,103 ,41 ,71 ,73 ,39 ,105 ,7]
list_shift32 = [32 ,224 ,32 ,224 ,32 ,224 ,32 ,224 ,32 ,224 ,32 ,224 ,32 ,224 ,32 ,224 ,32]
list_shift5 = [5 ,171 ,165 ,11 ,69 ,107 ,229 ,203 ,133 ,43 ,37 ,139 ,197 ,235 ,101 ,75 ,5]


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
        

print_rot(list_shift32)