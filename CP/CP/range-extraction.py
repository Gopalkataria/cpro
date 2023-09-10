test = [-6,-3,-2,-1,0,1,3,4,5,7,8,9,10,11,14,15,17,18,19,20]

def solution( arr  ) :
    arr.sort()
    sol = []
    sw  = False
    for i,elem in enumerate(arr) :
        if i+1 !=  len(arr) and elem+1  == arr[i+1] :
            if not sw : jum = elem
            sw = True

        else :
            if sw :
                if jum+1 == elem :
                    sol += [ jum , elem ]
                else :
                    sol += [ jum,  "-" , elem ]
                sw = False
            else :
                sol += [elem]
    return "".join([str(x) for x in sol])

print(solution( test  ))
