from random import randint 


n = 1000
m = 1000 
k = 100000
print(n,m,k)
for x in range(k) :
    print(randint(2,n-1), randint(1,m))