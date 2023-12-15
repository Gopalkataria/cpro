k = int(input())

def sol() :
    l = [int(x) for x in input().split()]
    n = l[0]
    k = l[1]

    m = n - k ; 
    if  m & 1 != 0 or k > n :
        print("NO")
        return
    
    if m >= k * (k -1) / 2 or k == 1 :
        print("YES")
        return
    print("NO")
    return






for _ in range(k) :
    sol()