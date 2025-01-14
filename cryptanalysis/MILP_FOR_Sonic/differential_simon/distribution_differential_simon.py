import sys
import random
import os
import time

from model_differential_simon import *
from print_result_simon import print_trail,print_all


def get_input_equivalent(NBR_round):
    sum = 0
    list_dec = []
    for i in range(H_SONIC_SIZE):
        cur = int(x[0,i].getAttr('xn')) | int(x[0,i+H_SONIC_SIZE].getAttr('xn'))
        if(cur==1):
            list_dec.append(i)
        sum += cur
    list_input = []
    for i in range(sum):
        #compute the distance to the next 1
        dec = list_dec[i]#the shift until the next 1 in the representation
        inputl,inputr = [x[0,shiffte(i,dec)].getAttr('xn') for i in range(H_SONIC_SIZE)],[x[0,shiffte(i,dec)+H_SONIC_SIZE].getAttr('xn') for i in range(H_SONIC_SIZE)]
        outputl,outputr = [x[NBR_round-1,shiffte(i,dec)].getAttr('xn') for i in range(H_SONIC_SIZE)],[x[NBR_round-1,shiffte(i,dec)+H_SONIC_SIZE].getAttr('xn') for i in range(H_SONIC_SIZE)]
        list_input.append((inputl+inputr,outputl+outputr))
    return sum,list_input

#for a specific shifting rotation setup :
#SNL1 : shift non-linear 1
#SNL2 : shift non-linear 2
#SLR1 : shift linear right
#SLL1 : shift linear left 1
#SLL2 : shift linear left 2
# and for NBR_round, model and comput the minimum weight for any trail
def search_distribution_dif(SNL1,SNL2,SLR1,weight_min,NBR_round,size_test):
    
    tot_nbr_test = size_test
    batch_nbr_sol = size_test

    if(size_test==0):
        if(NBR_round==3):
            tot_nbr_test = 80000
            batch_nbr_sol = 80000
        if(NBR_round==4):
            tot_nbr_test = 50000
            batch_nbr_sol = 50000
        if(NBR_round==5):
            tot_nbr_test = 40000
            batch_nbr_sol = 40000
        if(NBR_round==6):
            tot_nbr_test = 10000
            batch_nbr_sol = 10000
    

    nbr_iter = tot_nbr_test // batch_nbr_sol

    solution_pool = []
    weight_min = [0,0,2,4,8,18,36]
    distribution = [0]*(weight_min[NBR_round]+100)
    distribution_equ = [0]*(weight_min[NBR_round]+100)

    for i in range(nbr_iter):

        add_constraint_full(SNL1,SNL2,SLR1,weight_min,NBR_round)
        remove_solutions(solution_pool,NBR_round)


        #set the parameter of the Gubrobi solver for faster result

        #set up the bound, wich mean that if the objectiv value goes below that value then the optimization stop
        #P.setParam(GRB.Param.BestObjStop,weight_min[NBR_round])

        #set a time limitation for the optimizer
        #P.Params.timeLimit = 36000
        P.setParam('OutputFlag',0)

        #to search for multiple solutions
        P.setParam(GRB.Param.PoolSolutions, batch_nbr_sol)
        P.setParam(GRB.Param.PoolSearchMode,2)
        P.setParam(GRB.Param.PoolGap,20)
        P.setParam(GRB.Param.FeasibilityTol,0.00000001)

        #P.setParam(GRB.Param.BestObjStop,weight_min)
        #write the model in a lp file
        P.write("distribution_sonic_dif_"+str(SONIC_SIZE)+"_"+str(NBR_round)+".lp")

        #return -1 

        #set the flag to 1 in order to have live information about the optimization status
        #set the flag to 0 in order to have no information until the optimization finish
        
        #start the optimization of the model
        P.optimize()
        #print("find ",P.solCount," solutions")
        nbr_sol = P.solCount
        list_equivalent = []
        for sol in range(nbr_sol):
            P.setParam(GRB.Param.SolutionNumber,sol)
            input,output = get_input_output(NBR_round)
            solution_pool.append((input,output))

            if(not ((input,output) in list_equivalent) and not(distribution[int(round(P.PoolObjVal))]==0)):
                list_equivalent += get_input_equivalent(NBR_round)[1]
                distribution[int(round(P.PoolObjVal))] += 1
            elif((input in list_equivalent) and int(round(P.PoolObjVal))==4):
                print_all(NBR_round)
            #check for each solution if it is a rottated version of an already found solution

            if(distribution[int(round(P.PoolObjVal))]==0):
                list_equivalent = get_input_equivalent(NBR_round)[1]
                time.sleep(2)
                #P.setParam(GRB.Param.SolutionNumber,sol)
                
                print_all(NBR_round)
                print_trail(SNL1,SNL2,SLR1,NBR_round)
                distribution[int(round(P.PoolObjVal))] += 1
            #if(int(round(P.PoolObjVal))==2):
            #    time.sleep(2)
            #    P.setParam(GRB.Param.SolutionNumber,sol)
            #    time.sleep(1)
            #    print_all(NBR_round+1)
            #    print_trail(SNL1,SNL2,SLR1,SLL1,SLL2,SLL3,M,NBR_round)
            

    print("distribution trail for ",nbr_sol)
    for i in range(len(distribution)-1):
        if(distribution[i]>0):
            print(i," ",distribution[i])


