import sys 
import matplotlib.pyplot as plt
import math
 
size_test =  1000 #10000 

# x-coordinates:
# possible distribution of clustering
x = range(0,size_test)

def read_dist_from_file(filename):
    File = open(filename,'r')
    line = File.readlines()
    print(line)
    #line = (line[0].split("\n"))[0].split("  ")
    line = line[2].split("  ")
    print(len(line))
    #print(line)
    res = [0]*len(line)
    for i in range(len(line)):
        try:
            res[i] = math.log2(int(line[i]))
        except ValueError:
            res[i] = 0
    print(res)
    return res

# y-coordinates:
#first the distribution of clustering for Sonic
#second the distribution of clustering for Simon
#both as log2 of the value

sonic1_dist = read_dist_from_file(sys.argv[1])
sonic2_dist = read_dist_from_file(sys.argv[2])

#simon_dist = read_dist_from_file(sys.argv[1])

# labels for bars
#tick_label = [str(i) for i in range(size_test)]
 
# plotting a bar chart

figures,axes = plt.subplots(1,2,constrained_layout=True)

SIZE_FONT = 40

#plt.bar(x, simon_dist, width = 0.8, color = ['blue'])
axes[0].bar(x, sonic1_dist, width = 0.8, color = ['green'])
axes[0].set_xlim(0,400)
axes[0].set_xlabel('cluster size for a differential',fontsize = SIZE_FONT)
axes[0].set_ylabel('log2 number of differential \nwith the same cluster size',fontsize=SIZE_FONT)
axes[0].set_title('Distribution cluster sizes Sonic256l \n (for 200_000 3-round differential)',fontsize=SIZE_FONT)
axes[0].tick_params(axis='both', labelsize=SIZE_FONT)


axes[1].bar(x, sonic2_dist, width = 0.8, color = ['green'])
axes[1].set_xlim(0,400)
axes[1].set_xlabel('cluster size for a differential',fontsize=SIZE_FONT)
axes[1].set_ylabel('log2 number of differential \nwith the same cluster size',fontsize=SIZE_FONT)
axes[1].set_title('Distribution cluster sizes Sonic256 \n (for 200_000 3-round differential)',fontsize=SIZE_FONT)
axes[1].tick_params(axis='both', labelsize=SIZE_FONT)

#plt.xlim(0,4500)
#plt.xlim(0,500)
# naming the x-axis
#plt.xlabel('cluster size for a differential')
# naming the y-axis
#plt.ylabel('log2 number of differential \nwith the same cluster size')
# plot title
#plt.title('Distribution cluster sizes Sonic256l \n (for 200_000 3-round differential)')
 
plt.savefig("distribution_sonic256[18].pdf")
# function to show the plot
plt.show()
