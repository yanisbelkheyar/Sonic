import sys
import random
import os
import time

from model_differential import *
from print_result import print_trail,print_all

#set the objectiv function for the number of round
#the objectiv function is to minimize the sum of the weight of left half input + activity patern
def set_obj_1(NBR_round):
    Q = 0
    for i in range(NBR_round):
        for j in range(H_SONIC_SIZE):
            Q += x[i,j] + A[i,j]

    #P.addConstr(Q>=8)
    
    P.setObjective(Q,GRB.MINIMIZE)

#!!this function can only be call after the optimization of the model!!
#
#can only be call after a first optimization to set the input and output dif to the one of the current solution
def add_input_constraint(SNL1,SNL2,SLR1,SLL1,SLL2,SLL3,M,NBR_round,input,output):
    if(not (P.NumConstrs==0)):
        P.remove(P.getConstrs()[0:P.NumConstrs-1])
    
    for i in range(SONIC_SIZE):
        P.addConstr(x[0,i]==input[i])
        P.addConstr(x[NBR_round,i]==output[i])

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

    set_obj_1(NBR_round)

    
def compute_proba(distribution):
    size = int(distribution[len(distribution)-1][0])+1
    tab = [0]*size
    for i in range(len(distribution)-1,-1,-1):
        dec = (bin(distribution[i][1]).split("0b"))[1]
        for j in range(len(dec)):
            if(dec[len(dec)-j-1]=='1'):
                tab[int(distribution[i][0])-j] += 1

    for j in range(size):
        for i in range(size-1,-1,-1):
            if(tab[i]>=2):
                tab[i-1] += 1
                tab[i] -= 2

    tot = []
    for i in range(size):
        if(not tab[i]==0):
            tot.append([i,tab[i]])
    return tot


def get_trail_spine(NBR_round):
    return [[x[round,i].getAttr('xn') for i in range(H_SONIC_SIZE)] for round in range(NBR_round)]


def remove_shifted_trails_spine(NBR_round):
    inv_15 = 111
    if(SONIC_SIZE==512):
        inv_15 = 239
    list_shift_trail = [ [[x[round,shiffte(i,(H_SONIC_SIZE-dec)*(inv_15**round))].getAttr('xn') for i in range(H_SONIC_SIZE)] for round in range(NBR_round)] for dec in range(H_SONIC_SIZE)]
    return list_shift_trail
            
#for a specific shifting rotation setup :
#SNL1 : shift non-linear 1
#SNL2 : shift non-linear 2
#SLR1 : shift linear right
#SLL1 : shift linear left 1
#SLL2 : shift linear left 2
# and for NBR_round, model and comput the minimum weight for any trail
def search_cluster_dif(SNL1,SNL2,SLR1,SLL1,SLL2,SLL3,M,weight_min,NBR_round,size_test):
    
    tot_nbr_test = size_test
    batch_nbr_sol = size_test

    if(size_test==0):
        if(NBR_round==3):
            tot_nbr_test = 50000
            batch_nbr_sol = 50000
        if(NBR_round==4):
            tot_nbr_test = 20000
            batch_nbr_sol = 20000
        if(NBR_round==5):
            tot_nbr_test = 10000
            batch_nbr_sol = 10000
        if(NBR_round==6):
            tot_nbr_test = 5000
            batch_nbr_sol = 5000
    

    nbr_iter = tot_nbr_test // batch_nbr_sol

    solution_pool = []

    for i in range(nbr_iter):

        add_constraint_full(SNL1,SNL2,SLR1,SLL1,SLL2,SLL3,M,weight_min,NBR_round)
        remove_solutions(solution_pool,NBR_round)

        #set the parameter of the Gubrobi solver for faster result

        #set up the bound, wich mean that if the objectiv value goes below that value then the optimization stop
        #P.setParam(GRB.Param.BestObjStop,weight_min[NBR_round])

        #set a time limitation for the optimizer
        #P.Params.timeLimit = 36000
        P.setParam('OutputFlag',1)

        #to search for multiple solutions
        P.setParam(GRB.Param.PoolSolutions, batch_nbr_sol)
        P.setParam(GRB.Param.PoolSearchMode,2)

        #P.setParam(GRB.Param.BestObjStop,weight_min)
        #write the model in a lp file
        #P.write("clust_sonic_dif_"+str(SONIC_SIZE)+"_"+str(NBR_round)+".lp")

        #return -1 

        #set the flag to 1 in order to have live information about the optimization status
        #set the flag to 0 in order to have no information until the optimization finish
        
        #start the optimization of the model
        P.optimize()
        print("find ",P.solCount," solutions")
        nbr_sol = P.solCount
        
        nbr_class_solution = 0
        list_diff = []
        weight = 0
        best_distribution = []
        list_shifted = []

        for sol in range(nbr_sol):
            P.setParam(GRB.Param.SolutionNumber,sol)
            input,output = get_input_output(NBR_round)
            trail_spine = get_trail_spine(NBR_round)
            if(not trail_spine in list_shifted):
                list_shifted += remove_shifted_trails_spine(NBR_round)
                list_diff.append((input,output))    
                solution_pool.append((input,output))
                nbr_class_solution += 1
                
        print(nbr_sol)
        print(nbr_class_solution)
            
        for sol in range(nbr_class_solution):
            #P.setParam(GRB.Param.SolutionNumber,random.randint(0,nbr_sol))
            input,output = list_diff[sol]

            #once one solution is found, add a new constrain to set the input and output diff to a certain value and restart the search with a larger pool of solution
            add_input_constraint(SNL1,SNL2,SLR1,SLL1,SLL2,SLL3,M,NBR_round,input,output)

            nbr_sol1 = 1000
            P.setParam(GRB.Param.PoolSolutions, nbr_sol1)
            P.setParam(GRB.Param.PoolSearchMode,2)
            P.setParam(GRB.Param.PoolGap,100)
            #P.setParam(GRB.Param.FeasibilityTol,0.000000001)

            P.setParam('OutputFlag',0)

            
            P.optimize()
            nSolution = P.SolCount

            P.setParam(GRB.Param.SolutionNumber,0)
            distribution = []
            
            distribution.append([P.PoolObjVal,0])
            cur_idx = 0
            
            for e in range(nSolution):
                P.setParam(GRB.Param.SolutionNumber,e)
                #to print the solution we need to seet a sleep, otherwise all printed solution will be the same
                #time.sleep(2)
                #print_trail(SNL1,SNL2,SLR1,SLL1,SLL2,SLL3,M,NBR_round)
                #print_all(NBR_ROUND)
                if(round(P.PoolObjVal+0.5)<=(distribution[cur_idx][0])):
                    distribution[cur_idx][1] += 1
                else:
                    cur_idx += 1
                    distribution.append([round(P.PoolObjVal+0.5),1])

            dist_befor = distribution
            distribution = compute_proba(distribution)
            if(len(best_distribution)==0 or distribution[0][0]<best_distribution[0][0]):
                best_distribution = distribution
                print("Distribution of Trail according to the weight")
                print(dist_befor)
                print(distribution)
                print("maximum differential probability considering clustering = ",distribution[0][0])                
                #print_trail(SNL1,SNL2,SLR1,SLL1,SLL2,SLL3,M,NBR_round)
                print("nbr solution = ",nSolution)
            weight = P.PoolObjVal


    print("For ",tot_nbr_test)
    print("max DP :",best_distribution[0][0])
    print("best distribution :",best_distribution)
    return weight


