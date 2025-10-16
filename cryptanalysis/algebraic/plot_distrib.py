#this file contain the code to print the distribution of degree for Sonic and Simon in the ideal case 
#and in the real case for 2 to 4 round


import sys 
import matplotlib.pyplot as plt
import math
from matplotlib.ticker import MaxNLocator
import matplotlib

def plot(dist,nbr_dist):

    x,y=[[] for i in range(nbr_dist)],[[] for i in range(nbr_dist)]
    

    for i in range(nbr_dist):
        print(i)
        for elt in dist[i]:
            x[i].append(elt[0])
            y[i].append(elt[1])


    #plt.plot(x1, y1 )
    #plt.plot(x2, y2 )
    #plt.bar(x, sonic_dist, width = 0.5, color = ['green'])


    
    figure, axes = plt.subplots(3,4,constrained_layout=True)
    width = 0.3

    SIZE_FONT = 20
    # plot distribution for Sonic in the left side

    #distribution for 2 round
    axes[0][1].bar(list(map(lambda x:x-(width/2),x[0])), y[0] ,width)
    axes[0][1].bar(list(map(lambda x:x+(width/2),x[1])), y[1] ,width)
    axes[0][1].set_xlabel('degree',fontsize = SIZE_FONT)
    axes[0][1].set_ylabel('#term',fontsize = SIZE_FONT)
    axes[0][1].set_title('Degree distribution \n 2 round Sonic256l',fontsize = SIZE_FONT)
    axes[0][1].xaxis.set_major_locator(MaxNLocator(integer=True))
    axes[0][1].tick_params(axis='both', labelsize=SIZE_FONT)


#distribution for 3 round

    axes[1][1].bar(list(map(lambda x:x-(width/2),x[2])), y[2] ,width)
    axes[1][1].bar(list(map(lambda x:x+(width/2),x[3])), y[3] ,width)
    axes[1][1].set_xlabel('degree',fontsize = SIZE_FONT)
    axes[1][1].set_ylabel('#term',fontsize = SIZE_FONT)
    axes[1][1].set_title('Degree distribution \n 3 round Sonic256l',fontsize = SIZE_FONT)
    axes[1][1].xaxis.set_major_locator(MaxNLocator(integer=True))
    axes[1][1].set_ylim(0,max(y[3])+10)
    axes[1][1].tick_params(axis='both', labelsize=SIZE_FONT)


#distribution for 4 round
    axes[2][1].bar(list(map(lambda x:x-(width/2),x[4])), y[4] ,width)
    axes[2][1].bar(list(map(lambda x:x+(width/2),x[5])), y[5] ,width)
    axes[2][1].set_xlabel('degree',fontsize = SIZE_FONT)
    axes[2][1].set_ylabel('#term',fontsize = SIZE_FONT)
    axes[2][1].set_title('Degree distribution \n 4 round Sonic256l',fontsize = SIZE_FONT)
    axes[2][1].xaxis.set_major_locator(MaxNLocator(integer=True))
    axes[2][1].set_ylim(0,max(y[5])+1000)
    axes[2][1].tick_params(axis='both', labelsize=SIZE_FONT)


# plot distribution for Simon in the right side


#distribution for 2 round 

    axes[0][2].bar(list(map(lambda x:x-(width/2),x[6])), y[6] ,width)
    axes[0][2].bar(list(map(lambda x:x+(width/2),x[7])), y[7] ,width)
    axes[0][2].set_xlabel('degree',fontsize = SIZE_FONT)
    axes[0][2].set_ylabel('#term',fontsize = SIZE_FONT)
    axes[0][2].set_title('Degree distribution \n 2 round Sonic256',fontsize = SIZE_FONT)
    axes[0][2].xaxis.set_major_locator(MaxNLocator(integer=True))
    axes[0][2].tick_params(axis='both', labelsize=SIZE_FONT)


#distribution for 3 round 
    axes[1][2].bar(list(map(lambda x:x-(width/2),x[8])), y[8] ,width)
    axes[1][2].bar(list(map(lambda x:x+(width/2),x[9])), y[9] ,width)
    axes[1][2].set_xlabel('degree',fontsize = SIZE_FONT)
    axes[1][2].set_ylabel('#term',fontsize = SIZE_FONT)
    axes[1][2].set_title('Degree distribution \n 3 round Sonic256',fontsize = SIZE_FONT)
    axes[1][2].xaxis.set_major_locator(MaxNLocator(integer=True))
    axes[1][2].set_ylim(0,max(y[3])+10)
    axes[1][2].tick_params(axis='both', labelsize=SIZE_FONT)


#distribution for 4 round 

    axes[2][2].bar(list(map(lambda x:x-(width/2),x[10])), y[10] ,width)
    axes[2][2].bar(list(map(lambda x:x+(width/2),x[11])), y[11] ,width)
    axes[2][2].set_xlabel('degree',fontsize = SIZE_FONT)
    axes[2][2].set_ylabel('#term',fontsize = SIZE_FONT)
    axes[2][2].set_title('Degree distribution \n 4 round Sonic256',fontsize = SIZE_FONT)
    axes[2][2].xaxis.set_major_locator(MaxNLocator(integer=True))
    axes[2][2].set_ylim(0,max(y[5])+1000)
    axes[2][2].tick_params(axis='both', labelsize=SIZE_FONT)



#distribution for 2 round 

    axes[0][3].bar(list(map(lambda x:x-(width/2),x[12])), y[12] ,width)
    axes[0][3].bar(list(map(lambda x:x+(width/2),x[13])), y[13] ,width)
    axes[0][3].set_xlabel('degree',fontsize = SIZE_FONT)
    axes[0][3].set_ylabel('#term',fontsize = SIZE_FONT)
    axes[0][3].set_title('Degree distribution \n 2 round Sonic512',fontsize = SIZE_FONT)
    axes[0][3].xaxis.set_major_locator(MaxNLocator(integer=True))
    axes[0][3].tick_params(axis='both', labelsize=SIZE_FONT)


#distribution for 3 round 
    axes[1][3].bar(list(map(lambda x:x-(width/2),x[14])), y[14] ,width)
    axes[1][3].bar(list(map(lambda x:x+(width/2),x[15])), y[15] ,width)
    axes[1][3].set_xlabel('degree',fontsize = SIZE_FONT)
    axes[1][3].set_ylabel('#term',fontsize = SIZE_FONT)
    axes[1][3].set_title('Degree distribution \n 3 round Sonic512',fontsize = SIZE_FONT)
    axes[1][3].xaxis.set_major_locator(MaxNLocator(integer=True))
    axes[1][3].set_ylim(0,max(y[3])+10)
    axes[1][3].tick_params(axis='both', labelsize=SIZE_FONT)


#distribution for 4 round 

    axes[2][3].bar(list(map(lambda x:x-(width/2),x[16])), y[16] ,width)
    axes[2][3].bar(list(map(lambda x:x+(width/2),x[17])), y[17] ,width)
    axes[2][3].set_xlabel('degree',fontsize = SIZE_FONT)
    axes[2][3].set_ylabel('#term',fontsize = SIZE_FONT)
    axes[2][3].set_title('Degree distribution \n 4 round Sonic512',fontsize = SIZE_FONT)
    axes[2][3].xaxis.set_major_locator(MaxNLocator(integer=True))
    axes[2][3].set_ylim(0,max(y[5])+1000)
    axes[2][3].tick_params(axis='both', labelsize=SIZE_FONT)


    #distribution for 2 round 

    axes[0][0].bar(list(map(lambda x:x-(width/2),x[18])), y[18] ,width)
    axes[0][0].bar(list(map(lambda x:x+(width/2),x[19])), y[19] ,width)
    axes[0][0].set_xlabel('degree',fontsize = SIZE_FONT)
    axes[0][0].set_ylabel('#term',fontsize = SIZE_FONT)
    axes[0][0].set_title('Degree distribution \n 2 round Simon',fontsize = SIZE_FONT)
    axes[0][0].xaxis.set_major_locator(MaxNLocator(integer=True))
    axes[0][0].tick_params(axis='both', labelsize=SIZE_FONT)


#distribution for 3 round 
    axes[1][0].bar(list(map(lambda x:x-(width/2),x[20])), y[20] ,width)
    axes[1][0].bar(list(map(lambda x:x+(width/2),x[21])), y[21] ,width)
    axes[1][0].set_xlabel('degree',fontsize = SIZE_FONT)
    axes[1][0].set_ylabel('#term',fontsize = SIZE_FONT)
    axes[1][0].set_title('Degree distribution \n 3 round Simon',fontsize = SIZE_FONT)
    axes[1][0].xaxis.set_major_locator(MaxNLocator(integer=True))
    axes[1][0].set_ylim(0,max(y[3])+10)
    axes[1][0].tick_params(axis='both', labelsize=SIZE_FONT)


#distribution for 4 round 

    axes[2][0].bar(list(map(lambda x:x-(width/2),x[22])), y[22] ,width)
    axes[2][0].bar(list(map(lambda x:x+(width/2),x[23])), y[23] ,width)
    axes[2][0].set_xlabel('degree',fontsize = SIZE_FONT)
    axes[2][0].set_ylabel('#term',fontsize = SIZE_FONT)
    axes[2][0].set_title('Degree distribution \n 4 round Simon',fontsize = SIZE_FONT)
    axes[2][0].xaxis.set_major_locator(MaxNLocator(integer=True))
    axes[2][0].set_ylim(0,max(y[5])+1000)
    axes[2][0].tick_params(axis='both', labelsize=SIZE_FONT)
    
    #plt.xlim(0,max(dist3[len(dist3)-1][0],dist4[len(dist4)-1][0]))
    #figure.xlim(0,max(dist3[len(dist1)-1][0],dist4[len(dist2)-1][0]))

    # naming the x-axis
    plt.xlabel('degree')
    plt.xlabel('degree')

    # naming the y-axis
    plt.ylabel('#term')
    plt.ylabel('#term')

    #plt.tight_layout()
    plt.savefig("distribution_degree_sonic.pdf")
    # function to show the plot
    plt.show()




#Ideal distribution for Simon for the left and right side
simon_l1 = [[1, 2], [2, 1]]
simon_r1 = [[1, 1]]
simon_l2 = [[1, 3], [2, 5], [3, 4], [4, 1]]
simon_r2 = [[1, 2], [2, 1]]
simon_l3 = [[1, 5], [2, 15], [3, 34], [4, 50], [5, 46], [6, 26], [7, 8], [8, 1]]
simon_r3 = [[1, 3], [2, 5], [3, 4], [4, 1]]
simon_l4 = [[1, 8], [2, 45], [3, 188], [4, 616], [5, 1566], [6, 3142], [7, 5048], [8, 6489], [9, 6618], [10, 5290], [11, 3260], [12, 1512], [13, 508], [14, 116], [15, 16], [16, 1]]
simon_r4 = [[1, 5], [2, 15], [3, 34], [4, 50], [5, 46], [6, 26], [7, 8], [8, 1]]

#Real distribution for Simon for the left and right side for size 256
real_simon_l1 = [[1, 2], [2, 1]]
real_simon_r1 = [[1, 1]]
real_simon_l2 = [[1, 3], [2, 3], [3, 5]]
real_simon_r2 = [[1, 2], [2, 1]]
real_simon_l3 = [[1, 3], [2, 5], [3, 28], [4, 47], [5, 8]]
real_simon_r3 = [[1, 3], [2, 3], [3, 5]]
real_simon_l4 = [[1, 4], [2, 13], [3, 62], [4, 279], [5, 743], [6, 621], [7, 260], [8, 17]]
real_simon_r4 = [[1, 3], [2, 5], [3, 28], [4, 47], [5, 8]]


#Ideal distribution for Sonic for the left and right side
sonic_l1 = [[1, 2], [2, 1]]
sonic_r1 = [[1, 3]]
sonic_l2 = [[1, 5], [2, 5], [3, 4], [4, 1]]
sonic_r2 = [[1, 6], [2, 3]]
sonic_l3 = [[1, 11], [2, 33], [3, 54], [4, 66], [5, 50], [6, 26], [7, 8], [8, 1]]
sonic_r3 = [[1, 15], [2, 15], [3, 12], [4, 3]]
sonic_l4 = [[1, 26], [2, 169], [3, 792], [4, 2346], [5, 5066], [6, 8398], [7, 11008], [8, 11649], [9, 9958], [10, 6862], [11, 3764], [12, 1608], [13, 516], [14, 116], [15, 16], [16, 1]]
sonic_r4 = [[1, 33], [2, 99], [3, 162], [4, 198], [5, 150], [6, 78], [7, 24], [8, 3]]

#Real distribution for Sonic for the left and right side
real_sonic_l1 = [[1, 2], [2, 1]]
real_sonic_r1 = [[1, 3]]
real_sonic_l2 = [[1, 5], [2, 5], [3, 4], [4, 1]]
real_sonic_r2 = [[1, 6], [2, 3]]
real_sonic_l3 = [[1, 7], [2, 31], [3, 56], [4, 65], [5, 49], [6, 26], [7, 8], [8, 1]]
real_sonic_r3 = [[1, 11], [2, 15], [3, 12], [4, 3]]
real_sonic_l4 = [[1, 14], [2, 91], [3, 519], [4, 1827], [5, 4548], [6, 8005], [7, 10817], [8, 11468], [9, 9734], [10, 6581], [11, 3480], [12, 1391], [13, 389], [14, 66], [15, 5]]
real_sonic_r4 = [[1, 19], [2,101], [3, 159], [4, 195], [5, 150], [6, 78], [7, 24], [8, 3]]

#Real distribution for Sonic for the left and right side
real_sonic256_18_l1 = [[1, 2], [2, 1]]
real_sonic256_18_r1 = [[1, 3]]

real_sonic256_18_l2 = [[1, 5], [2, 5], [3, 4], [4, 1]]
real_sonic256_18_r2 = [[1, 6], [2, 3]]

real_sonic256_18_l3 = [[1, 11], [2, 35], [3, 53], [4, 65], [5, 50], [6, 26], [7, 8], [8, 1]]
real_sonic256_18_r3 = [[1, 13], [2, 15], [3, 12], [4, 3]]

real_sonic256_18_l4 = [[1, 24], [2, 185], [3, 830], [4, 2491], [5, 5267], [6, 8926], [7, 11644], [8, 12129], [9, 9717], [10, 6068], [11, 2985], [12, 1157], [13, 347], [14, 78], [15, 12],[16,1]]
real_sonic256_18_r4 = [[1, 15], [2, 87], [3, 168], [4, 195], [5, 147], [6, 78], [7, 24], [8, 3]]



#Real distribution for Sonic for the left and right side
real_sonic256_16_l1 = [[1, 2], [2, 1]]
real_sonic256_16_r1 = [[1, 3]]

real_sonic256_16_l2 = [[1, 5], [2, 5], [3, 4], [4, 1]]
real_sonic256_16_r2 = [[1, 6], [2, 3]]

real_sonic256_16_l3 = [[1, 11], [2, 33], [3, 54], [4, 66], [5, 50], [6, 26], [7, 8], [8, 1]]
real_sonic256_16_r3 = [[1, 15], [2, 15], [3, 12], [4, 3]]

real_sonic256_16_l4 = [[1, 24], [2, 175], [3, 789], [4, 2514], [5, 5250], [6, 9034], [7, 11702], [8, 12237], [9, 9818], [10, 6134], [11, 3012], [12, 1165], [13, 348], [14,78 ], [15, 12],[16,1]]
real_sonic256_18_r4 = [[1, 15], [2, 87], [3, 168], [4, 195], [5, 147], [6, 78], [7, 24], [8, 3]]



#Real distribution for Simon for the left and right side for size 256
real_simon_512_l1 = [[1, 2], [2, 1]]
real_simon_512_r1 = [[1, 1]]

real_simon_512_l2 = [[1, 3], [2, 3], [3, 5]]
real_simon_512_r2 = [[1, 2], [2, 1]]

real_simon_512_l3 = [[1, 3], [2, 5], [3, 28], [4, 47], [5, 8]]
real_simon_512_r3 = [[1, 3], [2, 3], [3, 5]]

real_simon_512_l4 = [[1, 4], [2, 13], [3, 62], [4, 279], [5, 743], [6, 621], [7, 260], [8, 17]]
real_simon_512_r4 = [[1, 3], [2, 5], [3, 28], [4, 47], [5, 8]]


#Real distribution for Sonic for the left and right side
real_sonic_512_l1 = [[1, 2], [2, 1]]
real_sonic_512_r1 = [[1, 3]]

real_sonic_512_l2 = [[1, 5], [2, 5], [3, 4], [4, 1]]
real_sonic_512_r2 = [[1, 6], [2, 3]]

real_sonic_512_l3 = [[1, 11], [2, 33], [3, 54], [4, 66], [5, 50], [6, 26], [7, 8], [8, 1]]
real_sonic_512_r3 = [[1, 15], [2, 15], [3, 12], [4, 3]]

real_sonic_512_l4 = [[1, 26], [2, 169], [3, 797], [4, 2376], [5,5100], [6, 8399], [7, 10982], [8, 11620], [9, 9945], [10, 6860], [11, 3764], [12, 1608], [13, 516], [14, 116], [15, 16],[16,1]]
real_sonic_512_r4 = [[1, 33], [2, 99], [3, 162], [4, 198], [5, 150], [6, 78], [7, 24], [8, 3]]


#print the distribution for the left side for 2 to 4 round for sonic and simon
dist_sonic_18 = [sonic_l2,real_sonic256_18_l2,
        sonic_l3,real_sonic256_18_l3,
        sonic_l4,real_sonic256_18_l4]

dist_sonic_16 = [sonic_l2,real_sonic256_16_l2,
        sonic_l3,real_sonic256_16_l3,
        sonic_l4,real_sonic256_16_l4]

dist_simon = [simon_l2,real_simon_l2,
        simon_l3,real_simon_l3,
        simon_l4,real_simon_l4]

dist_sonic_512 = [sonic_l2,real_sonic_512_l2,
            sonic_l3,real_sonic_512_l3,
            sonic_l4,real_sonic_512_l4]

dist = dist_sonic_18+dist_sonic_16+dist_sonic_512+dist_simon
plot(dist,24)
