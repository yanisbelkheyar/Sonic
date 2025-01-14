import sys 
import matplotlib.pyplot as plt
import math
 
size_test =  100000 #1000

# x-coordinates:
# possible distribution of clustering
x = range(0,size_test)

def read_dist_from_file(filename):
    File = open(filename,'r')
    line = File.readlines()
    line = (line[0].split("\n"))[0].split("  ")
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

#sonic_dist = read_dist_from_file(sys.argv[1])

simon_dist = read_dist_from_file(sys.argv[1])

# labels for bars
#tick_label = [str(i) for i in range(size_test)]
 
# plotting a bar chart
plt.bar(x, simon_dist, width = 0.8, color = ['blue'])
#plt.bar(x, sonic_dist, width = 0.4, color = ['green'])

plt.xlim(0,300)
#plt.xlim(0,18)
# naming the x-axis
plt.xlabel('cluster size for a differential')
# naming the y-axis
plt.ylabel('log2 number of differential with the same cluster size')
# plot title
plt.title('Distribution cluster sizes for Simon up to size 300 (for 200_000 3-round differential)')
 
plt.savefig("distribution_sonic.pdf")
# function to show the plot
plt.show()
