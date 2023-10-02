from random import randint as randomint
a = 10**4
b = 10**4
c = 10**5
t = randomint(1,a) 
print(t) 
for x in range(t) :
    n = randomint(1,b) 
    print(n)
    for y in range(n) :
        print(randomint(1,c), end=" ")
    print("\n")