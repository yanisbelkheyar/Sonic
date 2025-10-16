import sys

if(int(sys.argv[1])==256):
    mult_shiffle = 5
else:
    mult_shiffle = 7

def rot_procrastinated(list_rotations,size,nbr_round):
    result = [[list_rotations[i]] for i in range(len(list_rotations))]
    for i in range(nbr_round):
        for j in range(len(list_rotations)):
            result[j].append(list_rotations[j]*(mult_shiffle**(nbr_round-i-1)) % size)

    for j in range(len(list_rotations)):
        print("int shift_"+str(list_rotations[j])+"_"+str(size)+"["+str(nbr_round+1)+"] = {",end="")
        for i in range(len(result[j])-1):
            print(result[j][i],',',end="")
        print(result[j][len(result[j])-1],'};')

if(int(sys.argv[1])==256):
    #list_rotations = [5,0,1,0,18,47,5]
    list_rotations = [5,0,1,0,16,40,5,16,56,72,88,96,104,120,80,32,64]
    rot_procrastinated(list_rotations,128,18)
else:
    list_rotations = [5,0,1,0,3,20,7]
    rot_procrastinated(list_rotations,256,12)