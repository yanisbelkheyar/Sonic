from model_differential_simon import *
from decimal import Decimal

#!!this function can only be call after the optimization of the model!!
#
#This function print the trail with minimum weight find after minimization of the objectiv function
def print_trail(SNL1,SNL2,SLR1,NBR_round):

    list_a = []

    weight = P.PoolObjVal
    
    print("tot weight for "+str(NBR_round)+" = "+str(weight))
    print(" rotation ("+str(SNL1)+","+str(SNL2)+"), shift "+str(SLR1))

    input_dif,output_dif = [0,0,0,0],[0,0,0,0]
    for i in range(H_SONIC_SIZE//2):
        for j in range(4):
            input_dif[j] += int(x[0,i+(j*H_SONIC_SIZE//2)].getAttr('xn'))*(2**(H_SONIC_SIZE//2-i-1))
            output_dif[j] += int(x[NBR_round,i+(j*H_SONIC_SIZE//2)].getAttr('xn'))*(2**(H_SONIC_SIZE//2-i-1))

    for i in range(4):
        print(hex(input_dif[i]),end=" , ")
    print()
    for i in range(4):
        print(hex(output_dif[i]),end=" , ")
    print()

    #print a trail with min weight and iterate over all trail with min weight
    for i in range(NBR_round):
        #if(i%2==0):
        print("X"+str(i)+":",end="          ")
        #else:
        #    print("B"+str(i//2)+":",end="          ")
        #print the state corresponding to the input of the non linear layer
        for j in range(H_SONIC_SIZE):
            if(x[i,j].getAttr('xn')==1):
                print("1",end="")
                list_a.append([i,j])
            else:
                print("-",end="")
                
        print("  ",end="")
        for j in range(H_SONIC_SIZE,SONIC_SIZE):
            if(x[i,j].getAttr('xn')==1):
                print("1",end="")
                list_a.append([i,j])
            else:
                print("-",end="")
        print("\nY"+str(i)+":",end="          ")
        for j in range(H_SONIC_SIZE):
            if(y[i,j].getAttr('xn')==1):
                print("1",end="")
                list_a.append([i,j])
            else:
                print("-",end="")
                
        print("  ",end="")
        for j in range(H_SONIC_SIZE,SONIC_SIZE):
            if(y[i,j].getAttr('xn')==1):
                print("1",end="")
                list_a.append([i,j])
            else:
                print("-",end="")
                
                #print("\noutput dif:  ",end="")
                #print the state corresponding to the output of the non linear layer
                #for j in range(H_SONIC_SIZE):
                #    if(y[i,j+H_SONIC_SIZE].getAttr("x")==1):
                #        print("1",end="")
                #    else:
                #        print("-",end="")

        print()

    print()
    print()

    #print("list index for active bit in x state")
    #for i in list_a:
    #    print(i,end=", ")
    #print()
    #print()


def print_all(NBR_round):
    for i in range(NBR_round):
        print("X",i,end="  ")
        for j in range(H_SONIC_SIZE):
                if(x[i,j].getAttr('xn')==1):
                    print("1",end="")
                else:
                    print("-",end="")
        print("  ",end="")
        for j in range(H_SONIC_SIZE,SONIC_SIZE):
            if(x[i,j].getAttr('xn')==1):
                print("1",end="")
            else:
                print("-",end="")
        print()
        print("A",i,end="  ")
        for j in range(H_SONIC_SIZE):
            if(A[i,j].getAttr('xn')==1):
                print("1",end="")
            else:
                print("-",end="")
        print()
        print("XP",i,end=" ")
        for j in range(H_SONIC_SIZE):
            if(xp[i,j].getAttr('xn')==1):
                print("1",end="")
            else:
                print("-",end="")
        print()
        print("Y",i,end="  ")
        for j in range(H_SONIC_SIZE):
                if(y[i,j].getAttr('xn')==1):
                    print("1",end="")
                else:
                    print("-",end="")
        print("  ",end="")
        for j in range(H_SONIC_SIZE,SONIC_SIZE):
            if(y[i,j].getAttr('xn')==1):
                print("1",end="")
            else:
                print("-",end="")
        print()
        print()
    print()
    print()
