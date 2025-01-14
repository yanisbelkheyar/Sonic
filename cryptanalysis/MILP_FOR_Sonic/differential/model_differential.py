"""
This file contain the main model use to search differential properties of Sonic permutation
there is all the steps function so as the variables used to model every step

"""


import sys
import gurobipy as gp
from gurobipy import GRB

SONIC_SIZE = int(sys.argv[2])
H_SONIC_SIZE = SONIC_SIZE//2
NBR_ROUND = 10

#create the Gurobi model
P = gp.Model("creat_equation")

#create all the necessary variable for model the cipher

#input of each round
x = P.addVars(NBR_ROUND,SONIC_SIZE, vtype=GRB.BINARY, name="x")

#output of the non_linear function (AND)
xp = P.addVars(NBR_ROUND,H_SONIC_SIZE, vtype=GRB.BINARY, name="xp")

#output of each round (before the permutation of each half of the state)
y = P.addVars(NBR_ROUND,SONIC_SIZE, vtype=GRB.BINARY, name="y")

#activity partern : A[i] = 1 iif (0,0,1) = (x[i],x[i+1],x[i+2])
A = P.addVars(NBR_ROUND,H_SONIC_SIZE, vtype=GRB.BINARY, name="A")

#intermediate variable to compute both Xor
e = P.addVars(NBR_ROUND,H_SONIC_SIZE, vtype=GRB.BINARY, name="e")

#output of the linear mixing layer before the left pi
f = P.addVars(NBR_ROUND,H_SONIC_SIZE, vtype=GRB.BINARY, name="f")


#return the value of a+plus mod half of the size of the state
def shiffte(a,plus):
    return (a+plus)%(H_SONIC_SIZE)


#add the non linear constraint for each bit of the round r
def NL_part(r,SNL1,SNL2):
    for i in range(H_SONIC_SIZE):
        create_NL(shiffte(i,SNL1),shiffte(i,SNL2),r)

#add the non linear constraint for bit a and b at round r
def create_NL(a,b,r):

    #constraint for the and
    P.addConstr(x[r,a]+x[r,b]-xp[r,a]>=0)

    #constraint for the non independency of 2 output bit depending on 3 input 
    P.addConstr(-x[r,a]+x[r,b]-x[r,b+(b-a) %H_SONIC_SIZE]-xp[r,a]+xp[r,b]>=-2)
    P.addConstr(-x[r,a]+x[r,b]-x[r,b+(b-a) %H_SONIC_SIZE]+xp[r,a]-xp[r,b]>=-2)
    

#add the xor constraint for every bit at round r (right xor)        
def xor_right(r,SLR1):
    for i in range(H_SONIC_SIZE):
        xor_3_bit_right_new(i,r,SLR1)

#add the linear constraint for a 3 bit xor at round r beetween the output of then non-linear function at index a, the input of the round at index a+SLR and the input of the round at index a+half of the state 
def xor_3_bit_right_new(a,r,SLR1):
    
    P.addConstr(xp[r,a]+x[r,shiffte(a,SLR1)]+x[r,a+H_SONIC_SIZE]-e[r,a]>=0)
    P.addConstr(-xp[r,a]-x[r,shiffte(a,SLR1)]-x[r,a+H_SONIC_SIZE]+e[r,a]>=-2)
    P.addConstr(-xp[r,a]+x[r,shiffte(a,SLR1)]+x[r,a+H_SONIC_SIZE]+e[r,a]>=0)
    P.addConstr(xp[r,a]-x[r,shiffte(a,SLR1)]+x[r,a+H_SONIC_SIZE]+e[r,a]>=0)
    P.addConstr(xp[r,a]+x[r,shiffte(a,SLR1)]-x[r,a+H_SONIC_SIZE]+e[r,a]>=0)
    P.addConstr(xp[r,a]-x[r,shiffte(a,SLR1)]-x[r,a+H_SONIC_SIZE]-e[r,a]>=-2)
    P.addConstr(-xp[r,a]-x[r,shiffte(a,SLR1)]+x[r,a+H_SONIC_SIZE]-e[r,a]>=-2)
    P.addConstr(-xp[r,a]+x[r,shiffte(a,SLR1)]-x[r,a+H_SONIC_SIZE]-e[r,a]>=-2)

#add the xor constraint for every bit at round r (left xor)        
def xor_left(r,SLL1,SLL2,SLL3):
    for i in range(H_SONIC_SIZE):
        xor_3_bit_left_new(i,r,SLL1,SLL2,SLL3)

#add the linear constraint for a 3 bit xor at round r beetween the output of then non-linear function at index a, the input of the round at index a+SLR and the input of the round at index a+half of the state 
def xor_3_bit_left_new(a,r,SLL1,SLL2,SLL3):
    
    P.addConstr(x[r,shiffte(a,SLL1)]+x[r,shiffte(a,SLL2)]+x[r,shiffte(a,SLL3)]-f[r,a]>=0)
    P.addConstr(-x[r,shiffte(a,SLL1)]-x[r,shiffte(a,SLL2)]-x[r,shiffte(a,SLL3)]+f[r,a]>=-2)
    P.addConstr(-x[r,shiffte(a,SLL1)]+x[r,shiffte(a,SLL2)]+x[r,shiffte(a,SLL3)]+f[r,a]>=0)
    P.addConstr(x[r,shiffte(a,SLL1)]-x[r,shiffte(a,SLL2)]+x[r,shiffte(a,SLL3)]+f[r,a]>=0)
    P.addConstr(x[r,shiffte(a,SLL1)]+x[r,shiffte(a,SLL2)]-x[r,shiffte(a,SLL3)]+f[r,a]>=0)
    P.addConstr(x[r,shiffte(a,SLL1)]-x[r,shiffte(a,SLL2)]-x[r,shiffte(a,SLL3)]-f[r,a]>=-2)
    P.addConstr(-x[r,shiffte(a,SLL1)]-x[r,shiffte(a,SLL2)]+x[r,shiffte(a,SLL3)]-f[r,a]>=-2)
    P.addConstr(-x[r,shiffte(a,SLL1)]+x[r,shiffte(a,SLL2)]-x[r,shiffte(a,SLL3)]-f[r,a]>=-2)

#add the linear constraint for the shuffulling at the end of each round
def shuffle(r):
    for i in range(SONIC_SIZE):
        P.addConstr(y[r,((i+H_SONIC_SIZE)%SONIC_SIZE)]==x[r+1,i])

#add the linear constraint for the multiplicativ shuffle for the right part
def shuffle_mul(r,M):
    for i in range(H_SONIC_SIZE):
        #mul shuffle for the right side
        P.addConstr(e[r,((i*M)%H_SONIC_SIZE)]==y[r,i+H_SONIC_SIZE])
        #mul shuffle for the left side
        P.addConstr(f[r,((i*M)%H_SONIC_SIZE)]==y[r,i])

#add the constraint for the activity paterne for each bit in the left part of the inpput of round r        
def set_001(r):
    for i in range(H_SONIC_SIZE):
        P.addConstr(-x[r,(i) % H_SONIC_SIZE]-x[r,((i+1)%H_SONIC_SIZE)]+x[r,((i+2)%H_SONIC_SIZE)]-A[r,((i+2)%H_SONIC_SIZE)]>=-2)
        P.addConstr(-x[r,(i) % H_SONIC_SIZE]+x[r,((i+1)%H_SONIC_SIZE)]+x[r,((i+2)%H_SONIC_SIZE)]-A[r,((i+2)%H_SONIC_SIZE)]>=-1)
        P.addConstr(x[r,(i) % H_SONIC_SIZE]-x[r,((i+1)%H_SONIC_SIZE)]+x[r,((i+2)%H_SONIC_SIZE)]-A[r,((i+2)%H_SONIC_SIZE)]>=-1)
        P.addConstr(x[r,(i) % H_SONIC_SIZE]+x[r,((i+1)%H_SONIC_SIZE)]+x[r,((i+2)%H_SONIC_SIZE)]-A[r,((i+2)%H_SONIC_SIZE)]>=0)
        P.addConstr(-x[r,(i) % H_SONIC_SIZE]-x[r,((i+1)%H_SONIC_SIZE)]-x[r,((i+2)%H_SONIC_SIZE)]-A[r,((i+2)%H_SONIC_SIZE)]>=-3)
        P.addConstr(-x[r,(i) % H_SONIC_SIZE]+x[r,((i+1)%H_SONIC_SIZE)]-x[r,((i+2)%H_SONIC_SIZE)]-A[r,((i+2)%H_SONIC_SIZE)]>=-2)
        P.addConstr(x[r,(i) % H_SONIC_SIZE]-x[r,((i+1)%H_SONIC_SIZE)]-x[r,((i+2)%H_SONIC_SIZE)]-A[r,((i+2)%H_SONIC_SIZE)]>=-2)
        P.addConstr(x[r,(i) % H_SONIC_SIZE]+x[r,((i+1)%H_SONIC_SIZE)]-x[r,((i+2)%H_SONIC_SIZE)]+A[r,((i+2)%H_SONIC_SIZE)]>=0)

        #P.addConstr(A[r,((i+2)%H_SONIC_SIZE)]>=x[r,((i+2)%H_SONIC_SIZE)])

#set the objectiv function for the number of round
#the objectiv function is to minimize the sum of the weight of left half input + activity patern
def set_obj(NBR_round,min_weight):
    Q = 0
    for i in range(NBR_round):
        for j in range(H_SONIC_SIZE):
            Q += x[i,j] + A[i,j]

    P.addConstr(Q>=min_weight[NBR_round])
    
    P.setObjective(Q,GRB.MINIMIZE)


#add the constraint for NBR_round of the round function with the rotation value specify as argument to the model P
def add_constraint(SNL1,SNL2,SLR1,SLL1,SLL2,SLL3,M,min_weight,NBR_round):
    if(not (P.NumConstrs==0)):
        P.remove(P.getConstrs()[0:P.NumConstrs-1])

    P.addConstr(x[0,0]+x[1,0]>=1) 


    for round in range(NBR_round-1,NBR_ROUND):
        for i in range(SONIC_SIZE):
            if(round>NBR_round):
                P.addConstr(x[round,i]==0)
                if(i<H_SONIC_SIZE):
                    P.addConstr(A[round,i]==0)
            if(i<H_SONIC_SIZE):
                P.addConstr(xp[round,i]==0)
                P.addConstr(e[round,i]==0)
                P.addConstr(f[round,i]==0)
            P.addConstr(y[round,i]==0)

    for i in range(NBR_round-1):
        NL_part(i,SNL1,SNL2)
        xor_right(i,SLR1)
        xor_left(i,SLL1,SLL2,SLL3)
        shuffle_mul(i,M)
        shuffle(i)
        set_001(i)

    set_001(NBR_round-1)

    set_obj(NBR_round,min_weight)


#add the constraint for NBR_round of the round function with the rotation value specify as argument to the model P
def add_constraint_full(SNL1,SNL2,SLR1,SLL1,SLL2,SLL3,M,min_weight,NBR_round):
    if(not (P.NumConstrs==0)):
        P.remove(P.getConstrs()[0:P.NumConstrs-1])

    P.addConstr(x[0,0]+x[0,H_SONIC_SIZE]>=1)
    #P.addConstr(x[0,0]+x[0,1]==2)

    for round in range(NBR_round,NBR_ROUND):
        for i in range(SONIC_SIZE):
            if(round>NBR_round):
                P.addConstr(x[round,i]==0)
            if(i<H_SONIC_SIZE):
                P.addConstr(A[round,i]==0)
                P.addConstr(xp[round,i]==0)
                P.addConstr(e[round,i]==0)
                P.addConstr(f[round,i]==0)
            P.addConstr(y[round,i]==0)

    for i in range(NBR_round):
        NL_part(i,SNL1,SNL2)
        xor_right(i,SLR1)
        xor_left(i,SLL1,SLL2,SLL3)
        shuffle_mul(i,M)
        shuffle(i)
        set_001(i)

    #set_001(NBR_round-1)

    set_obj(NBR_round,min_weight)


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
        P.addConstr(c_input>=-val_input)
        P.addConstr(c_output>=-val_output)

