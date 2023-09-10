def trim_map( arr  ) :
    n = len(arr[0])
    return [ x[1:n-1] for x in arr[1:n-1]  ]

def map( arr ) :
    if len(arr) == 0 :
        return []
    n = len(arr[0])
    if n == 0 :
        return []
    else :
        return arr[0][:-1]  +  [ arr[x][n-1] for x in range(n) ] + arr[n-1][0:n-1][::-1 ] + [ arr[x][0] for x in range(n-2,0,-1)  ] + map(trim_map(arr))


a = lambda m : [ [x + 1 for x in range(n*m , n*m + m ) ] for n in range(m)  ]
for x in range(9) :
    print(a(x) )
    print(map(a(x)))
