def intput() :
    return int(input())

A = [[]]


t = intput() 

def sums( s , l ) : 
    n = 0 
    for x in l :
        k = [ y for y in l ]
        k.remove(x)
        s2 = sum(k) 
        if s2 == s :
            n += 1 
        if s2 >  s :
            n += sums(s , k )
    return n 

    
while t > 0 :
    t = t - 1
    n = intput() 
    nums = [ int(x) for x in input().split() ] 
    s = sum(nums) 
    if s == 1 :
        i = 0 
        for x in nums :
            if x == 0 :
                i = i + 1 
        print(2**i)
    else :
        print(sums(s-1 , nums ))


