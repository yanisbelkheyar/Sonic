size = 128
M = Mod(1+X^size,2)
for(i=1,size-1,for(j=i+1,size,P=Mod(1+X^i+X^j,M);if(P^(size-1)*P==1 && hammingweight(lift(lift(P^(size-1))))==7,print1("[0,",i,",",j,"],"))))  

for(i=1,size-1,for(j=i+1,size,P=Mod(1+X^i+X^j,M);if(P^(size-1)*P==1 && hammingweight(lift(lift(P^(size-1))))<=3,print1("[0,",i,",",j,"],"),print1(hammingweight(lift(lift(P^(size-1)))),"\n"))))  
