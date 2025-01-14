#this file contain the code to print the distribution of degree for Sonic and Simon in the ideal case 
#and in the real case for 2 to 4 round


import sys 
import matplotlib.pyplot as plt
import math
from matplotlib.ticker import MaxNLocator

def plot(dist,nbr_dist):

    x,y=[[] for i in range(nbr_dist)],[[] for i in range(nbr_dist)]
    

    for i in range(nbr_dist):
        for elt in dist[i]:
            x[i].append(elt[0])
            y[i].append(elt[1])


    #plt.plot(x1, y1 )
    #plt.plot(x2, y2 )
    #plt.bar(x, sonic_dist, width = 0.5, color = ['green'])

    figure, axes = plt.subplots(3,2)
    width = 0.3
    
    # plot distribution for Sonic in the left side

    #distribution for 2 round
    axes[0][0].bar(list(map(lambda x:x-(width/2),x[0])), y[0] ,width)
    axes[0][0].bar(list(map(lambda x:x+(width/2),x[1])), y[1] ,width)
    axes[0][0].set_xlabel('degree')
    axes[0][0].set_ylabel('#term')
    axes[0][0].set_title('Degree distribution for 2 round Sonic')
    #axes[0][0].set_xticklabels(axes[0][0].get_xticks())
    axes[0][0].xaxis.set_major_locator(MaxNLocator(integer=True))

#distribution for 3 round
    axes[1][0].bar(list(map(lambda x:x-(width/2),x[2])), y[2] ,width)
    axes[1][0].bar(list(map(lambda x:x+(width/2),x[3])), y[3] ,width)
    axes[1][0].set_xlabel('degree')
    axes[1][0].set_ylabel('#term')
    axes[1][0].set_title('Degree distribution for 3 round Sonic')
    axes[1][0].xaxis.set_major_locator(MaxNLocator(integer=True))
    axes[1][0].set_ylim(0,max(y[3])+10)

#distribution for 4 round
    axes[2][0].bar(list(map(lambda x:x-(width/2),x[4])), y[4] ,width)
    axes[2][0].bar(list(map(lambda x:x+(width/2),x[5])), y[5] ,width)
    axes[2][0].set_xlabel('degree')
    axes[2][0].set_ylabel('#term')
    axes[2][0].set_title('Degree distribution for 4 round Sonic')
    axes[2][0].xaxis.set_major_locator(MaxNLocator(integer=True))
    axes[2][0].set_ylim(0,max(y[5])+1000)

# plot distribution for Simon in the right side


#distribution for 2 round 
    axes[0][1].bar(list(map(lambda x:x-(width/2),x[6])), y[6] ,width)
    axes[0][1].bar(list(map(lambda x:x+(width/2),x[7])), y[7] ,width)
    axes[0][1].set_xlabel('degree')
    axes[0][1].set_ylabel('#term')
    axes[0][1].set_title('Degree distribution for 2 round Simon')
    axes[0][1].xaxis.set_major_locator(MaxNLocator(integer=True))

#distribution for 3 round 
    axes[1][1].bar(list(map(lambda x:x-(width/2),x[8])), y[8] ,width)
    axes[1][1].bar(list(map(lambda x:x+(width/2),x[9])), y[9] ,width)
    axes[1][1].set_xlabel('degree')
    axes[1][1].set_ylabel('#term')
    axes[1][1].set_title('Degree distribution for 3 round Simon')
    axes[1][1].xaxis.set_major_locator(MaxNLocator(integer=True))
    axes[1][1].set_ylim(0,max(y[3])+10)

#distribution for 4 round 
    axes[2][1].bar(list(map(lambda x:x-(width/2),x[10])), y[10] ,width)
    axes[2][1].bar(list(map(lambda x:x+(width/2),x[11])), y[11] ,width)
    axes[2][1].set_xlabel('degree')
    axes[2][1].set_ylabel('#term')
    axes[2][1].set_title('Degree distribution for 4 round Simon')
    axes[2][1].xaxis.set_major_locator(MaxNLocator(integer=True))
    axes[2][1].set_ylim(0,max(y[5])+1000)

    #plt.xlim(0,max(dist3[len(dist3)-1][0],dist4[len(dist4)-1][0]))
    #figure.xlim(0,max(dist3[len(dist1)-1][0],dist4[len(dist2)-1][0]))

    # naming the x-axis
    plt.xlabel('degree')
    plt.xlabel('degree')

    # naming the y-axis
    plt.ylabel('#term')
    plt.ylabel('#term')
    
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

#Real distribution for Simon for the left and right side
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
real_sonic_r4 = [[1, 15], [2, 87], [3, 168], [4, 195], [5, 147], [6, 78], [7, 24], [8, 3]]


#print the distribution for the left side for 2 to 4 round for sonic and simon
dist_sonic = [sonic_l2,real_sonic_l2,
        sonic_l3,real_sonic_l3,
        sonic_l4,real_sonic_l4]

dist_simon = [simon_l2,real_simon_l2,
        simon_l3,real_simon_l3,
        simon_l4,real_simon_l4]


plot(dist_sonic+dist_simon,12)