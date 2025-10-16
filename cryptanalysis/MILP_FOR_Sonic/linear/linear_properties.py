import sys
from linear_trail_search_sonic import *
from distribution_linear import *
from cluster_linear import *

def get_args():

    if(len(sys.argv)>=3):

        nbr_round_start,nbr_round_end = 1,7

        if(int(sys.argv[2])==512):
            #512 rotation
            SLR1,SNL1,SNL2,SLL1,SLL2,SLL3,M = 5,0,1,0,3,20,7

        
        if(int(sys.argv[2])==256):
            #256 heavy inverse 
            SLR1,SNL1,SNL2,SLL1,SLL2,SLL3,M = 5,0,1,0,18,47,5
            #256 light inverse = 7
            #SLR1,SNL1,SNL2,SLL1,SLL2,SLL3,M = 5,0,1,0,16,40,5


        if(sys.argv[1]=="-r"):

            min_weight = [0,0,0,0,0,17,26,0,0,0]

            list_rot = [[0,1,64],[0,1,65],[0,2,64],[0,2,66],[0,3,64],[0,3,67],[0,4,64],[0,4,68],[0,5,64],[0,5,69],[0,6,64],[0,6,70],[0,7,64],[0,7,71],[0,8,64],[0,8,72],[0,9,64],[0,9,73],[0,10,64],[0,10,74],[0,11,64],[0,11,75],[0,12,64],[0,12,76],[0,13,64],[0,13,77],[0,14,64],[0,14,78],[0,15,64],[0,15,79],[0,16,64],[0,16,80],[0,17,64],[0,17,81],[0,18,64],[0,18,82],[0,19,64],[0,19,83],[0,20,64],[0,20,84],[0,21,64],[0,21,85],[0,22,64],[0,22,86],[0,23,64],[0,23,87],[0,24,64],[0,24,88],[0,25,64],[0,25,89],[0,26,64],[0,26,90],[0,27,64],[0,27,91],[0,28,64],[0,28,92],[0,29,64],[0,29,93],[0,30,64],[0,30,94],[0,31,64],[0,31,95],[0,32,64],[0,32,96],[0,33,64],[0,33,97],[0,34,64],[0,34,98],[0,35,64],[0,35,99],[0,36,64],[0,36,100],[0,37,64],[0,37,101],[0,38,64],[0,38,102],[0,39,64],[0,39,103],[0,40,64],[0,40,104],[0,41,64],[0,41,105],[0,42,64],[0,42,106],[0,43,64],[0,43,107],[0,44,64],[0,44,108],[0,45,64],[0,45,109],[0,46,64],[0,46,110],[0,47,64],[0,47,111],[0,48,64],[0,48,112],[0,49,64],[0,49,113],[0,50,64],[0,50,114],[0,51,64],[0,51,115],[0,52,64],[0,52,116],[0,53,64],[0,53,117],[0,54,64],[0,54,118],[0,55,64],[0,55,119],[0,56,64],[0,56,120],[0,57,64],[0,57,121],[0,58,64],[0,58,122],[0,59,64],[0,59,123],[0,60,64],[0,60,124],[0,61,64],[0,61,125],[0,62,64],[0,62,126],[0,63,64],[0,63,127],[0,64,65],[0,64,66],[0,64,67],[0,64,68],[0,64,69],[0,64,70],[0,64,71],[0,64,72],[0,64,73],[0,64,74],[0,64,75],[0,64,76],[0,64,77],[0,64,78],[0,64,79],[0,64,80],[0,64,81],[0,64,82],[0,64,83],[0,64,84],[0,64,85],[0,64,86],[0,64,87],[0,64,88],[0,64,89],[0,64,90],[0,64,91],[0,64,92],[0,64,93],[0,64,94],[0,64,95],[0,64,96],[0,64,97],[0,64,98],[0,64,99],[0,64,100],[0,64,101],[0,64,102],[0,64,103],[0,64,104],[0,64,105],[0,64,106],[0,64,107],[0,64,108],[0,64,109],[0,64,110],[0,64,111],[0,64,112],[0,64,113],[0,64,114],[0,64,115],[0,64,116],[0,64,117],[0,64,118],[0,64,119],[0,64,120],[0,64,121],[0,64,122],[0,64,123],[0,64,124],[0,64,125],[0,64,126],[0,64,127]]
            
            max_weight = 0
            list_good = []
            for rot in list_rot:
                SLL2 = rot[1]
                SLL3 = rot[2]
                for j in range(3,32):
                    if(j%2!=0):
                        M = j
                        w = search_trail_lin(SNL1,SNL2,SLR1,SLL1,SLL2,SLL3,M,min_weight,5)
                        if(w!=None and w>max_weight):
                            min_weight[6] = w
                            list_good = [(rot,j)]
                            max_weight = w
                        if(w!=None and w==max_weight):
                            list_good.append((rot,j))
            
            print("max weight for 6 round = ",max_weight)
            for elt in list_rot:
                print(elt)

        if(sys.argv[1]=="-t"):
            if(len(sys.argv)==4):
                nbr_round_start,nbr_round_end = int(sys.argv[3]),int(sys.argv[3])+1
            elif(len(sys.argv)==5):
                nbr_round_start,nbr_round_end = int(sys.argv[3]),int(sys.argv[4])
            #search for differential trails        
            min_weight = [0,0,0,0,0,0,0,0,0,0]

            for i in range(nbr_round_start,nbr_round_end):
                search_trail_lin(SNL1,SNL2,SLR1,SLL1,SLL2,SLL3,M,min_weight,i,0)
            
        if(sys.argv[1]=="-td"):
            if(len(sys.argv)==4):
                nbr_round_start,nbr_round_end = int(sys.argv[3]),int(sys.argv[3])+1
            elif(len(sys.argv)==5):
                nbr_round_start,nbr_round_end = int(sys.argv[3]),int(sys.argv[4])
            #search for differential trails        
            min_weight = [0,0,0,0,0,0,0,0,0,0]

            for i in range(nbr_round_start,nbr_round_end):
                search_trail_lin(SNL1,SNL2,SLR1,SLL1,SLL2,SLL3,M,min_weight,i,2)

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
