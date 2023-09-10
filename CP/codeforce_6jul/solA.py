t = int(input())

def findmin( n , k , suslevels ) :
    power = []
    for x in range(n-1) :
        power += [ abs( suslevels[x+1] - suslevels[x] ) ]
    power.sort()
    power.reverse()
    power = power[k-1:]
    return sum(power)


for x in range( t ) :
    inp = input().split()
    n, k =  int(inp[0]) , int(inp[1])
    suspicion = [ int(x) for x in  input().split() ]
    print(findmin(n,k,suspicion))
