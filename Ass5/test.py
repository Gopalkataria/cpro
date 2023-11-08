from random import randint

for _ in range(10**5) :
    k = randint(0,9) 
    print(k , end="" ) 
print("")
k = 0 ; 
print(10**5)
for _ in range(2*(10**5)) :
    k  = randint(0,2)
    if k == 0 :
        print("2 1 e")
    if k == 1 :
        print("2 2 f") 
    else :
        print("1")


