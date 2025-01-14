#Compute the distribution for the ideal case for Simon and Sonic degree distribution

def distrib(dl,dr):
    new_dist_l = [[i+1,0] for i in range(dl[len(dl)-1][0]*2)]
    for i in range(dl[len(dl)-1][0]):
        for j in range(dl[len(dl)-1][0]):
            #print(dl[i][0]+dl[j][0],":",dl[i][1]*dl[j][1])
            new_dist_l[dl[i][0]+dl[j][0]-1][1] += dl[i][1]*dl[j][1] 

    for i in range(len(dl)):
        new_dist_l[dl[i][0]-1][1] += dl[i][1]
    for i in range(len(dr)):
        new_dist_l[dl[i][0]-1][1] += dr[i][1]


    #for sonic ideal distrib
    new_dist_r = [[i+1,dl[i][1]*3] for i in range(len(dl))]
    #for simon ideal distrib
    #new_dist_r = [[i+1,dl[i][1]] for i in range(len(dl))]
    return new_dist_l,new_dist_r


def print_distrib(d):
    for i in range(len(d)):
        if(d[i][1]>=1):
            print(d[i][0],":",d[i][1])

dl,dr = [[1,1]],[[1,1]]

for i in range(4):
    dl,dr = distrib(dl,dr)
    print(dl)
    print(dr)
