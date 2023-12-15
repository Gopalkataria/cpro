digs = "1234567890"
k = 0 
for _ in range(1000) :
    inp = input() 

    for ch in inp :
        if ch in digs :
            k += 10 * int(ch) 
            break 
    for ch in reversed( inp ) :
        if ch in digs :
            k += int(ch )
            break 
print( k )