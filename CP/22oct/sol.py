t = int(input())
from math import log , ceil ; 
while t != 0:
    n = int(input())
    a = list(map(int, input().split()))
    ans = 0
    for i in range(1, n):
        if a[i] < a[i-1]:
            k = ceil(log(a[i-1]/a[i], 2))
            a[i] *= (2**k)
            ans += k 
    print(ans)

    t -= 1
    