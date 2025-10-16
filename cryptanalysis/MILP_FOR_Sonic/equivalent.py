import random

size = 128

def pi(a,shift):
     return [a[(i*shift)%len(a)] for i in range(len(a))]

def shift(a,dec):
    return [a[(i+dec)%len(a)] for i in range(len(a))]



sh = random.randint(0,size)

x1 = [random.randint(0,1) for i in range(size)]

x2 = shift(x1,sh)

z1 = pi(x1,15)
y1 = pi(z1,15)

z2 = pi(x2,15)
y2 = pi(z2,15)

print("shift is ",sh)

#print(128-sh % size)
print((size-sh)*111**2 % size)
#print((sh*111) % size)
#print(111**(sh) % size)
#print(111**(size-sh) % size)

print(x1)
print(x2)
print(z2)

for i in range(size):
    if(not x1[(i+sh)%size]==x2[(i)%size] or not x2[(i)%size]==z2[(111*i)%size]):
        print("x1 =",x1[(i+sh)%size]," x2 =",x2[i]," z2 =",z2[(111*i)%size])
        
print("the good value is :",end="")
for i in range(size):
    if(y1==shift(y2,i)):
        print(i)

