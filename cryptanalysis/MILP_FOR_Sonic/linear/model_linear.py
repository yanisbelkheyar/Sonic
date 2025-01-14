"""
This file contain the main model use to search linear properties of Sonic permutation
there is all the steps function so as the variables used to model every step

"""


import sys
import gurobipy as gp
from gurobipy import GRB

SONIC_SIZE = int(sys.argv[2])
H_SONIC_SIZE = SONIC_SIZE//2
NBR_ROUND = 8

#create the Gurobi model
P = gp.Model("creat_equation")

#create all the necessary variable for model the cipher

#input of each round
x = P.addVars(NBR_ROUND,SONIC_SIZE, vtype=GRB.BINARY, name="x")

#output of each round (before the permutation of each half of the state)
y = P.addVars(NBR_ROUND,SONIC_SIZE, vtype=GRB.BINARY, name="y")

#variable to make the pi
z = P.addVars(NBR_ROUND,SONIC_SIZE, vtype=GRB.BINARY, name="z")

#odd runs
A = P.addVars(NBR_ROUND,H_SONIC_SIZE, vtype=GRB.BINARY, name="A")

#intermediate variable to compute both Xor
e = P.addVars(NBR_ROUND,H_SONIC_SIZE, vtype=GRB.BINARY, name="e")
f = P.addVars(NBR_ROUND,H_SONIC_SIZE, vtype=GRB.BINARY, name="f")

xp = P.addVars(NBR_ROUND,H_SONIC_SIZE, vtype=GRB.BINARY, name="xp")

#v = P.addVars(NBR_ROUND,H_SONIC_SIZE, vtype=GRB.BINARY, name="v")



#return the value of a+plus mod half of the size of the state
def shiffte(a,plus):
    return (a+plus)%(H_SONIC_SIZE)

        
#add the non linear constraint for each bit of the round r
def NL_part(r,SNL1,SNL2):
    for i in range(H_SONIC_SIZE):
        fork_3_bit_NL(i,r)
        create_NL(i,r)
        
        
#add the non linear constraint for bit a and b at round r
def create_NL(a,r):
    #constraint for the and

    P.addConstr(x[r,a+H_SONIC_SIZE] + x[r,(a+1)%H_SONIC_SIZE + H_SONIC_SIZE] - xp[r,(a+1)%H_SONIC_SIZE]>=0)

    
def fork_3_bit_NL(a,r):

    P.addConstr(-f[r,a]+xp[r,a]+x[r,a]>=0)
    P.addConstr(f[r,a]-xp[r,a]+x[r,a]>=0)
    P.addConstr(f[r,a]+xp[r,a]-x[r,a]>=0)
    P.addConstr(-f[r,a]-xp[r,a]-x[r,a]>=-2)

    
#add the xor constraint for every bit at round r (right xor)        
def fork_left_2(r,SLR1):
    for i in range(H_SONIC_SIZE):
        fork_2_bit_left_new(i,r,SLR1)

#add the linear constraint for a 3 bit xor at round r beetween the output of then non-linear function at index a, the input of the round at index a+SLR and the input of the round at index a+half of the state 
def fork_2_bit_left_new(a,r,SLR1):
    P.addConstr(-x[r,shiffte(a,-SLR1)+H_SONIC_SIZE]+e[r,a]+f[r,a]>=0)
    P.addConstr(x[r,shiffte(a,-SLR1)+H_SONIC_SIZE]-e[r,a]+f[r,a]>=0)
    P.addConstr(x[r,shiffte(a,-SLR1)+H_SONIC_SIZE]+e[r,a]-f[r,a]>=0)
    P.addConstr(-x[r,shiffte(a,-SLR1)+H_SONIC_SIZE]-e[r,a]-f[r,a]>=-2)

#add the xor constraint for every bit at round r (left xor)        
def fork_left(r,SLL1,SLL2,SLL3):
    for i in range(H_SONIC_SIZE):
        fork_3_bit_left_new(i,r,SLL1,SLL2,SLL3)
        
#add the linear constraint for a 3 bit xor at round r beetween the output of then non-linear function at index a, the input of the round at index a+SLR and the input of the round at index a+half of the state 
def fork_3_bit_left_new(a,r,SLL1,SLL2,SLL3):
    P.addConstr(y[r,shiffte(a,-SLL1)]+y[r,shiffte(a,-SLL2)]+y[r,shiffte(a,-SLL3)]-e[r,a]>=0)
    P.addConstr(-y[r,shiffte(a,-SLL1)]-y[r,shiffte(a,-SLL2)]-y[r,shiffte(a,-SLL3)]+e[r,a]>=-2)
    P.addConstr(-y[r,shiffte(a,-SLL1)]+y[r,shiffte(a,-SLL2)]+y[r,shiffte(a,-SLL3)]+e[r,a]>=0)
    P.addConstr(y[r,shiffte(a,-SLL1)]-y[r,shiffte(a,-SLL2)]+y[r,shiffte(a,-SLL3)]+e[r,a]>=0)
    P.addConstr(y[r,shiffte(a,-SLL1)]+y[r,shiffte(a,-SLL2)]-y[r,shiffte(a,-SLL3)]+e[r,a]>=0)
    P.addConstr(y[r,shiffte(a,-SLL1)]-y[r,shiffte(a,-SLL2)]-y[r,shiffte(a,-SLL3)]-e[r,a]>=-2)
    P.addConstr(-y[r,shiffte(a,-SLL1)]-y[r,shiffte(a,-SLL2)]+y[r,shiffte(a,-SLL3)]-e[r,a]>=-2)
    P.addConstr(-y[r,shiffte(a,-SLL1)]+y[r,shiffte(a,-SLL2)]-y[r,shiffte(a,-SLL3)]-e[r,a]>=-2)


def xor_2_bit_right_first(r):
    for i in range(H_SONIC_SIZE):
        #P.addConstr(z[r,i+H_SONIC_SIZE]==y[r,i+H_SONIC_SIZE])
        P.addConstr(y[r,i+H_SONIC_SIZE]==x[r,i+H_SONIC_SIZE])

        
#add the linear constraint for the shuffulling at the end of each round
def shuffle(r,M):
    for i in range(SONIC_SIZE):
        P.addConstr(z[r,i]==x[r+1,(i+H_SONIC_SIZE)%SONIC_SIZE])
    for i in range(H_SONIC_SIZE):
        P.addConstr(y[r,((i*M)%H_SONIC_SIZE)] == z[r,i])
        P.addConstr(y[r,((i*M)%H_SONIC_SIZE)+H_SONIC_SIZE] == z[r,i+H_SONIC_SIZE])
        
#add the constraint for the activity paterne for each bit in the left part of the inpput of round r
#we set the constraint to active an activity patern if there is a patterne 010 or 01110 since for linear weight
#the weight is the size of any sequence in between two 0 if it is even, and the size +1 if the size is odd
#therefore for even lenght the hamming weight will do the job, and for od length we consider the smallest sequence
#which are 010 and 01110, and for those we set to 1 the activity pattern
def set_odd(r):  
    for i in range(H_SONIC_SIZE):

        P.addConstr(x[r,(i % H_SONIC_SIZE)+H_SONIC_SIZE]+x[r,((i+1)%H_SONIC_SIZE)+H_SONIC_SIZE]+x[r,((i+2)%H_SONIC_SIZE)+H_SONIC_SIZE]-A[r,i]>=0)
        P.addConstr(x[r,(i % H_SONIC_SIZE)+H_SONIC_SIZE]+x[r,((i+1)%H_SONIC_SIZE)+H_SONIC_SIZE]-x[r,((i+2)%H_SONIC_SIZE)+H_SONIC_SIZE]-A[r,i]>=-1)
        P.addConstr(x[r,(i % H_SONIC_SIZE)+H_SONIC_SIZE]-x[r,((i+1)%H_SONIC_SIZE)+H_SONIC_SIZE]+x[r,((i+2)%H_SONIC_SIZE)+H_SONIC_SIZE]+A[r,i]>=0)
        P.addConstr(x[r,(i % H_SONIC_SIZE)+H_SONIC_SIZE]-x[r,((i+1)%H_SONIC_SIZE)+H_SONIC_SIZE]-x[r,((i+2)%H_SONIC_SIZE)+H_SONIC_SIZE]-A[r,i]>=-2)
        P.addConstr(-x[r,(i % H_SONIC_SIZE)+H_SONIC_SIZE]+x[r,((i+1)%H_SONIC_SIZE)+H_SONIC_SIZE]+x[r,((i+2)%H_SONIC_SIZE)+H_SONIC_SIZE]-A[r,i]>=-1)
        P.addConstr(-x[r,(i % H_SONIC_SIZE)+H_SONIC_SIZE]+x[r,((i+1)%H_SONIC_SIZE)+H_SONIC_SIZE]-x[r,((i+2)%H_SONIC_SIZE)+H_SONIC_SIZE]-A[r,i]>=-2)
        P.addConstr(-x[r,(i % H_SONIC_SIZE)+H_SONIC_SIZE]-x[r,((i+1)%H_SONIC_SIZE)+H_SONIC_SIZE]+x[r,((i+2)%H_SONIC_SIZE)+H_SONIC_SIZE]-A[r,i]>=-2)
        P.addConstr(-x[r,(i % H_SONIC_SIZE)+H_SONIC_SIZE]-x[r,((i+1)%H_SONIC_SIZE)+H_SONIC_SIZE]-x[r,((i+2)%H_SONIC_SIZE)+H_SONIC_SIZE]-A[r,i]>=-3)
        
        P.addConstr(A[r,i]<=x[r,((i+1)%H_SONIC_SIZE)+H_SONIC_SIZE])

        
#set the objectiv function for the number of round
#the objectiv function is to minimize the sum of the weight of left half input + 1 for each 010 and 01110 paterne
#the linear weight computed is a lower bound of the linear weight.
def set_obj(NBR_round,weight_min):
    Q = 0
    for i in range(NBR_round):
        for j in range(H_SONIC_SIZE):
            Q += x[i,j+H_SONIC_SIZE] + A[i,j]

    P.addConstr(Q>=weight_min[NBR_round])
    P.setObjective(Q,GRB.MINIMIZE)


#add the constraint for NBR_round of the round function with the rotation value specify as argument to the model P
def add_constraint(SNL1,SNL2,SLR1,SLL1,SLL2,SLL3,M,weight_min,NBR_round):
    if(not (P.NumConstrs==0)):
        P.remove(P.getConstrs()[0:P.NumConstrs-1])
    
    P.addConstr(x[NBR_round-1,0]+x[NBR_round-1,0+H_SONIC_SIZE]>=1)
    
    for round in range(NBR_round-1,NBR_ROUND):
        for i in range(SONIC_SIZE):
            if(round>NBR_round-1):
                P.addConstr(x[round,i]==0)
                if(i<H_SONIC_SIZE):
                    P.addConstr(A[round,i]==0)
            if(i<H_SONIC_SIZE):
                P.addConstr(e[round,i]==0)
                P.addConstr(f[round,i]==0)
                P.addConstr(xp[round,i]==0)
            P.addConstr(y[round,i]==0)
            P.addConstr(z[round,i]==0)

    for i in range(NBR_round-1):
        shuffle(i,M)
        xor_2_bit_right_first(i)
        fork_left(i,SLL1,SLL2,SLL3)
        fork_left_2(i,SLR1)
        NL_part(i,SNL1,SNL2)
        set_odd(i)

    set_odd(NBR_round-1)
    set_obj(NBR_round,weight_min)


#add the constraint for NBR_round of the round function with the rotation value specify as argument to the model P
def add_constraint_full(SNL1,SNL2,SLR1,SLL1,SLL2,SLL3,M,weight_min,NBR_round):
    if(not (P.NumConstrs==0)):
        P.remove(P.getConstrs()[0:P.NumConstrs-1])
    
    P.addConstr(x[NBR_round-1,0]+x[NBR_round-1,0+H_SONIC_SIZE]>=1)
    
    for round in range(NBR_round,NBR_ROUND):
        for i in range(SONIC_SIZE):
            if(round>NBR_round):
                P.addConstr(x[round,i]==0)
                    
            if(i<H_SONIC_SIZE):
                P.addConstr(A[round,i]==0)
                P.addConstr(e[round,i]==0)
                P.addConstr(f[round,i]==0)
                P.addConstr(xp[round,i]==0)
            P.addConstr(y[round,i]==0)
            P.addConstr(z[round,i]==0)

    for i in range(NBR_round):
        shuffle(i,M)
        xor_2_bit_right_first(i)
        fork_left(i,SLL1,SLL2,SLL3)
        fork_left_2(i,SLR1)
        NL_part(i,SNL1,SNL2)
        set_odd(i)

    #set_odd(NBR_round)
    set_obj(NBR_round,weight_min)


def get_input_output(NBR_round):
    return [x[0,i].getAttr('xn') for i in range(SONIC_SIZE)], [x[NBR_round,i].getAttr('xn') for i in range(SONIC_SIZE)]

#take a liste of previously found differential over NBR_round round and add constraint to exclude those solution
def remove_solutions(list_prev_sol,NBR_round):
    for sol in list_prev_sol:
        input,output = sol
        c_input,c_output = 0,0
        val_input,val_output = 0,0
        for i in range(len(input)):
            if(input[i]==1):
                c_input -= x[0,i]
                val_input += 1
            if(input[i]==0):
                c_input += x[0,i]
            if(output[i]==1):
                c_output -= x[NBR_round-1,i]
                val_output += 1
            if(output[i]==0):
                c_output += x[NBR_round-1,i]
        P.addConstr(c_input>=-val_input+1)
        P.addConstr(c_output>=-val_output+1)
