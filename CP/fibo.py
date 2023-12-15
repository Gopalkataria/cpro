fibs = [0, 1 ]

for x in range(2, 100) :
    fibs.append(fibs[x - 1] + fibs[x - 2])


print(fibs) 
