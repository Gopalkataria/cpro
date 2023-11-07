t = int(input()) 
k = 0 
while t >  0 : 
    t = t -1 
    m = input()
    if m == "Against" :
        k = k-1 
    else :
        k = k + 1 


if k > 0 :
    print("Yes" )
else :
    print("No") 
