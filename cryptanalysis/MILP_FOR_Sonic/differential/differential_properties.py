import sys
from diff_trail_search_sonic import *
from distribution_differential import *
from cluster_differential import *

def get_args():

    if(len(sys.argv)>=4):

        SLR1,SNL1,SNL2,SLL1,SLL2,SLL3,M = 5,0,1,0,7,32,15 

        nbr_round_start,nbr_round_end = 1,7

        if(sys.argv[1]=="-t"):
            if(len(sys.argv)==4):
                nbr_round_start,nbr_round_end = int(sys.argv[3]),int(sys.argv[3])+1
            elif(len(sys.argv)==5):
                nbr_round_start,nbr_round_end = int(sys.argv[3]),int(sys.argv[4])
            #search for differential trails  
            #             0 1 2 3 4 5 6 7 8 9       
            min_weight = [0,3,0,0,0,0,0,0,0,0]

            for i in range(nbr_round_start,nbr_round_end):
                search_trail_dif(SNL1,SNL2,SLR1,SLL1,SLL2,SLL3,M,min_weight,i,0)
        
        if(sys.argv[1]=="-tt"):
            if(len(sys.argv)==4):
                nbr_round_start,nbr_round_end = int(sys.argv[3]),int(sys.argv[3])+1
            elif(len(sys.argv)==5):
                nbr_round_start,nbr_round_end = int(sys.argv[3]),int(sys.argv[4])
            #search for differential trails        
            min_weight = [0,0,3,0,0,0,0,0,0]

            for i in range(nbr_round_start,nbr_round_end):
                search_trail_dif(SNL1,SNL2,SLR1,SLL1,SLL2,SLL3,M,min_weight,i,1)

        elif(sys.argv[1]=="-d"):
            size_sample = 0
            if(len(sys.argv)==5):
                size_sample = int(sys.argv[3])
                nbr_round_start,nbr_round_end = int(sys.argv[4]),int(sys.argv[4])+1
            elif(len(sys.argv)==6):
                size_sample = int(sys.argv[3])
                nbr_round_start,nbr_round_end = int(sys.argv[4]),int(sys.argv[5])

            #search for the distribution
            weight_min = [0,0,2,4,8,18,32]
            for i in range(nbr_round_start,nbr_round_end):
                search_distribution_dif(SNL1,SNL2,SLR1,SLL1,SLL2,SLL3,M,weight_min,i,size_sample)
            print()
        elif(sys.argv[1]=="-c"):
            size_sample = 0
            if(len(sys.argv)==5):
                size_sample = int(sys.argv[3])
                nbr_round_start,nbr_round_end = int(sys.argv[4]),int(sys.argv[4])+1
            elif(len(sys.argv)==6):
                size_sample = int(sys.argv[3])
                nbr_round_start,nbr_round_end = int(sys.argv[4]),int(sys.argv[5])

            #search for the clustering effect
            weight_min = [0,0,2,4,8,18,32]
            for i in range(nbr_round_start,nbr_round_end):
                search_cluster_dif(SNL1,SNL2,SLR1,SLL1,SLL2,SLL3,M,weight_min,i,size_sample)
            print()

    else:
        print("order of the arguments : size p0 nl1 nl2 theta0 theta1 theta2 m (nbr_round_start nbr_round_end)")
        print("by defautl searching for 1 to 6 round trails")


get_args()
