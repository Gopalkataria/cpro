#!/bin/python3 

from random import randint
n = 15
k = randint( 1 , (n//10) )
print( n , k ) 
for _ in range(n) :
    k = randint(0,4) 
    print(k , end="") 