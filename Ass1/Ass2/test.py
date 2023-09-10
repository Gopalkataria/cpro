#!/bin/python3  
from random import randint, shuffle 

i = randint(1,10**6)
i = i*2 + 1 
print(i)

l = []

for x in range(int((i-1)/2)) :
    it = randint(1,10**9) 
    l += [ it, it ]

un = randint(1,10**9) 

with open("new" , "w" ) as f :
    f.write(str(un)) 


l += [ un ] 
shuffle(l)

for x in l :
    print(x) 


