import sys 
import matplotlib.pyplot as plt
import math

size = 30

is_dif = True
is_lin = False

is_heavy = False

# x-coordinates:
# possible distribution of clustering
x = range(0,size)

def read_dist_from_file(filename):
    File = open(filename,'r')
    line = File.readlines()
    line = (line[0].split("\n"))[0].split("  ")
    print(len(line))
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
#both as log2 of the values

#sonic_dist = read_dist_from_file(sys.argv[1])

log_dist_3,log_dist_4,log_dist_5,log_dist_6 = [0]*size,[0]*size,[0]*size,[0]*size
dist_3,dist_4,dist_5,dist_6 = [0]*size,[0]*size,[0]*size,[0]*size

#differential distribution
if(is_dif):

    if(is_heavy):
        #for the heavy
        dist_3[4],dist_3[5],dist_3[6],dist_3[7],dist_3[8],dist_3[9],dist_3[10] = (1),(1),(5),(16),(235),(412),(2160)
        dist_4[12],dist_4[13],dist_4[14],dist_4[15],dist_4[16] = (1),(2),(8),(15),(29)
        dist_5[26],dist_5[27] = (1),(7)

    else:
        #for the light

        dist_3[4],dist_3[5],dist_3[6],dist_3[7],dist_3[8],dist_3[9],dist_3[10] = (1),(1),(7),(19),(233),(465),(2359)
        dist_4[12],dist_4[13],dist_4[14],dist_4[15],dist_4[16] = (1),(3),(6),(15),(24)
        dist_5[26] = (19)
    

    #dist_3[4],dist_3[6],dist_3[7],dist_3[8],dist_3[9],dist_3[10] = (1),(6),(7),(106),(80),(907)
    #dist_4[12],dist_4[14],dist_4[15],dist_4[16] = (2),(6),(1),(14)
    #dist_5[18],dist_5[20],dist_5[22] = (10),(10),(33)
    #dist_6[36] = (491)

    if(is_heavy):
        #for the heavy
        log_dist_3[4],log_dist_3[5],log_dist_3[6],log_dist_3[7],log_dist_3[8],log_dist_3[9],log_dist_3[10] = math.log2(1),math.log2(1),math.log2(5),math.log2(16),math.log2(235),math.log2(412),math.log2(2160)
        log_dist_4[12],log_dist_4[13],log_dist_4[14],log_dist_4[15],log_dist_4[16] = math.log2(1),math.log2(2),math.log2(8),math.log2(15),math.log2(29)
        log_dist_5[26],log_dist_5[27] = math.log2(1),math.log2(7)

    else:
        #for the light
        
        log_dist_3[4],log_dist_3[5],log_dist_3[6],log_dist_3[7],log_dist_3[8],log_dist_3[9],log_dist_3[10] = math.log2(1),math.log2(1),math.log2(7),math.log2(19),math.log2(233),math.log2(465),math.log2(2359)
        log_dist_4[12],log_dist_4[13],log_dist_4[14],log_dist_4[15],log_dist_4[16] = math.log2(1),math.log2(3),math.log2(6),math.log2(15),math.log2(24)
        log_dist_5[26] = math.log2(19)
        
    #log_dist_3[4],log_dist_3[6],log_dist_3[7],log_dist_3[8],log_dist_3[9],log_dist_3[10] = math.log2(1),math.log2(6),math.log2(7),math.log2(106),math.log2(80),math.log2(907)
    #log_dist_4[12],log_dist_4[14],log_dist_4[15],log_dist_4[16] = math.log2(2),math.log2(6),math.log2(1),math.log2(14)
    #log_dist_5[18],log_dist_5[20],log_dist_5[22] = math.log2(10),math.log2(10),math.log2(33)
    #log_dist_6[36] = math.log2(491)

if(is_lin):

    if(is_heavy):
        #for the heavy
        dist_3[4],dist_3[6],dist_3[8],dist_3[10],dist_3[12],dist_3[14],dist_3[16] = (1),(15),(350),(3019),(1),(22),(12)
        dist_4[12],dist_4[14],dist_4[16] = (1),(8),(34)
        dist_5[26] = (1)

    else:
        #for the light
        dist_3[4],dist_3[6],dist_3[8],dist_3[10],dist_3[12],dist_3[14],dist_3[16] = (1),(16),(341),(2914),(3),(24),(13)
        dist_4[12],dist_4[14],dist_4[16] = (1),(6),(19)
        dist_5[26] = (10)
    
   

    #linear distribution
    #dist_3[4],dist_3[6],dist_3[8] = (1),(8),(169)
    #dist_4[12],dist_4[14],dist_4[16] = (1),(5),(16)
    #dist_5[18],dist_5[20],dist_5[22] = (5),(10),(51)
    #dist_6[36] = (21)

    if(is_heavy):
        #for the heavy
        log_dist_3[4],log_dist_3[6],log_dist_3[8],log_dist_3[10],log_dist_3[12],log_dist_3[14],log_dist_3[16] = math.log2(1),math.log2(15),math.log2(350),math.log2(3019),math.log2(1),math.log2(22),math.log2(12)
        log_dist_4[12],log_dist_4[14],log_dist_4[16] = math.log2(1),math.log2(8),math.log2(34)
        log_dist_5[26] = math.log2(1)

    else:
        #for the light
        log_dist_3[4],log_dist_3[6],log_dist_3[8],log_dist_3[10],log_dist_3[12],log_dist_3[14],log_dist_3[16] = math.log2(1),math.log2(16),math.log2(341),math.log2(2914),math.log2(3),math.log2(24),math.log2(13)
        log_dist_4[12],log_dist_4[14],log_dist_4[16] = math.log2(1),math.log2(6),math.log2(19)
        log_dist_5[26] = math.log2(10)
    
    
    #log_dist_3[4],log_dist_3[6],log_dist_3[8],log_dist_3[9] = math.log2(1),math.log2(8),math.log2(169),math.log2(11)
    #log_dist_4[12],log_dist_4[14],log_dist_4[16] = math.log2(1),math.log2(5),math.log2(16)
    #log_dist_5[18],log_dist_5[20],log_dist_5[22] = math.log2(5),math.log2(10),math.log2(51)
    #log_dist_6[36] = math.log2(21)
    
# labels for bars
 
# plotting a bar chart
plt.bar(list(map(lambda x: x-0.4 ,x)), log_dist_3, width = 0.8, color = ['blue'],label="3 round")
plt.bar(list(map(lambda x: x ,x)), log_dist_4, width = 0.8, color = ['red'],label="4 round")
plt.bar(list(map(lambda x: x+0.4 ,x)), log_dist_5, width = 0.8, color = ['green'],label="5 round")
#plt.bar(x, log_dist_6, width = 0.8, color = ['yellow'],label="6 round")

for index,value in enumerate(dist_3):
    if(value!=0):
        plt.text(index-0.4,log_dist_3[index],str(value))

for index,value in enumerate(dist_4):
    if(value!=0):
        plt.text(index,log_dist_4[index],str(value))

for index,value in enumerate(dist_5):
    if(value!=0):
        plt.text(index+0.4,log_dist_5[index],str(value))

#for index,value in enumerate(dist_6):
#    if(value!=0):
#        plt.text(index-0.2,log_dist_6[index],str(value))

plt.xlim(0,size)
plt.xticks(x)
#plt.xlim(0,18)
# naming the x-axis
if(is_dif):
    plt.xlabel('weight of differential trail spine')
    # naming the y-axis
    plt.ylabel('log2 # differential trail spine')
    # plot title
    plt.title('Histogram of differential trail spine for Sonic256[18]')

if(is_lin):    
    plt.xlabel('weight of linear trail spine')
    plt.ylabel('log2 # linear trail spine')
    plt.title('Histogram of linear trail spine for Sonic256[18]')


plt.legend()

plt.savefig("distribution_trail_spine.pdf")
# function to show the plot
plt.show()
