import sys
import random
import os
import time
from operator import xor

from model_differential_simon import *
from print_result_simon import print_trail,print_all

            
#for a specific shifting rotation setup :
#SNL1 : shift non-linear 1
#SNL2 : shift non-linear 2
#SLR1 : shift linear right
#SLL1 : shift linear left 1
#SLL2 : shift linear left 2
# and for NBR_round, model and comput the minimum weight for any trail
def search_trail_dif(SNL1,SNL2,SLR1,min_weight,NBR_round,test):

    if(test==1):
       add_constraint_full(SNL1,SNL2,SLR1,min_weight,NBR_round)
    else:
        add_constraint(SNL1,SNL2,SLR1,min_weight,NBR_round)

    #set the parameter of the Gubrobi solver for faster result

    #set up the bound, wich mean that if the objectiv value goes below that value then the optimization stop
    #P.setParam(GRB.Param.BestObjStop,weight_min)

    #set a time limitation for the optimizer
    #P.Params.timeLimit = 36000
    P.setParam('OutputFlag',1)

    #to search for multiple solutions
    #P.setParam(GRB.Param.PoolSolutions, nbr_sol)
    #P.setParam(GRB.Param.PoolSearchMode,1)
    #write the model in a lp file
    #P.write("model/trails/trail_sonic_dif_"+str(SONIC_SIZE)+"_"+str(NBR_round)+".lp")

    #return -1 

    #set the flag to 1 in order to have live information about the optimization status
    #set the flag to 0 in order to have no information until the optimization finish
    
    #start the optimization of the model
    #Sol = P.optimize()
    #"""
    P.optimize()

    weight = P.ObjVal

    print_trail(SNL1,SNL2,SLR1,NBR_round)
    print()
    print()
    print_all(NBR_round)
    
    return weight

