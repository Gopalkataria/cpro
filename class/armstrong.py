for x in range(500) :
    k = [ int(y) for y in str(x) ]
    t = 0 
    for y in k :
        t += y**(len(k))
    if t == x :
        print(x)
