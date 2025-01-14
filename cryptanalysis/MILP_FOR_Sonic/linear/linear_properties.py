import sys
from linear_trail_search_sonic import *
from distribution_linear import *
from cluster_linear import *

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
            min_weight = [0,0,0,0,0,0,0,0,0,0]

            for i in range(nbr_round_start,nbr_round_end):
                search_trail_lin(SNL1,SNL2,SLR1,SLL1,SLL2,SLL3,M,min_weight,i)

        elif(sys.argv[1]=="-d"):
            size_sample = 0
            if(len(sys.argv)==5):
                size_sample = int(sys.argv[3])
                nbr_round_start,nbr_round_end = int(sys.argv[4]),int(sys.argv[4])+1
            elif(len(sys.argv)==6):
                size_sample = int(sys.argv[3])
                nbr_round_start,nbr_round_end = int(sys.argv[4]),int(sys.argv[5])

            #search for the distribution
            weight_min = [0,0,2,4,12,18,36]
            for i in range(nbr_round_start,nbr_round_end):
                search_distribution_lin(SNL1,SNL2,SLR1,SLL1,SLL2,SLL3,M,weight_min,i,size_sample)
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
            weight_min = [0,0,2,4,8,18,36]
            for i in range(nbr_round_start,nbr_round_end):
                search_cluster_lin(SNL1,SNL2,SLR1,SLL1,SLL2,SLL3,M,weight_min,i,size_sample)
            print()

    else:
        print("order of the arguments : size p0 nl1 nl2 theta0 theta1 theta2 m (nbr_round_start nbr_round_end)")
        print("by defautl searching for 1 to 6 round trails")


get_args()
