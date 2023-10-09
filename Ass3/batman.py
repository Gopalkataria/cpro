m = 0
grid = []

def findpaths(x, y):
    if (x, y) in grid:
        return 0
    if x < 1 or y < 1 or y > m:
        return 0
    if x == 1:
        return 1
    a = findpaths(x - 1, y - 2)
    b = findpaths(x - 1, y + 2)
    c = findpaths(x - 2, y - 1)
    d = findpaths(x - 2, y + 1)
    return a + b + c + d

inp = [int(x) for x in input().split()]
n, m, k = inp[0], inp[1], inp[2]

for x in range(k):
    inp = [int(x) for x in input().split()]
    grid.append((inp[0], inp[1]))

for x in range(1, m + 1):
    print(findpaths(n, x), end=" ")
