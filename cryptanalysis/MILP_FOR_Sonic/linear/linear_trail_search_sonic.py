#!/usr/bin/env sage
# coding=utf-8

import sys
import random
import os
import time
from operator import xor
#from gurobipy import *
from model_linear import *
from print_result import print_trail,print_all

#for a specific shifting rotation setup :
#SNL1 : shift non-linear 1
#SNL2 : shift non-linear 2
#SLR1 : shift linear right
#SLL1 : shift linear left 1
#SLL2 : shift linear left 2
# and for NBR_round, model and comput the minimum weight for any trail
def search_trail_lin(SNL1,SNL2,SLR1,SLL1,SLL2,SLL3,M,weight_min,NBR_round,test):

    if(test==1):
        add_constraint_full(SNL1,SNL2,SLR1,SLL1,SLL2,SLL3,M,weight_min,NBR_round);
    elif(test==2):
        add_constraint_duplex(SNL1,SNL2,SLR1,SLL1,SLL2,SLL3,M,weight_min,NBR_round);
    else:
        add_constraint(SNL1,SNL2,SLR1,SLL1,SLL2,SLL3,M,weight_min,NBR_round);

    #set up the bound, wich mean that if the objectiv value goes below that value then the optimization stop
    P.setParam(GRB.Param.BestObjStop,weight_min[NBR_round])
    
    #P.setParam(GRB.Param.Cutoff,20)

    #P.Params.timeLimit = 36000
    
    #write the model in a lp file
    #P.write("model/trails/trail_sonic_lin_"+str(SONIC_SIZE)+"_"+str(NBR_round)+".lp")

    #return -1 

    #set the flag to 1 in order to have live information about the optimization status
    #set the flag to 0 in order to have no information until the optimization finish
    P.setParam('OutputFlag',1)
    P.optimize()

    print_trail(SNL1,SNL2,SLR1,SLL1,SLL2,SLL3,M,NBR_round)
    print()
    print()
    print_all(NBR_round)

