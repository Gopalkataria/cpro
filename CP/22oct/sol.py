t = int(input())
a = [] 

def checknonint(a):
    if len(a) == 0 or len(a) == 1:
        return "NO"
    for i in range(len(a)):
        for j in range(i+1,len(a)):
            if a[i][1] < a[j][0] or a[j][1] < a[i][0]:
                return "YES"
    return "NO"                

for i in range(t):
    k = input().split()
    op = ( k[0] == "+")
    x = (int(k[1]))    
    y = (int(k[2])) 
    
    if op:
        a.append((x,y))
    else:
        a.remove((x,y))
    k  = checknonint(a)
    print(k)