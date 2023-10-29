t = int(input())

def checkmainstring( s ):
    zer = 0 
    on  = 0 
    for i in range( len(s) -1  ):
        if s[i] == s[i+1]:
            if s[i] == '0':
                zer += 1 
            else:
                on += 1
    return zer, on
            

while ( t != 0 ):

    k = input() 
    mainstring = input() 
    helpstring = input() 
    zer , on = checkmainstring( mainstring )
    zer1 , on1 = checkmainstring( helpstring )
    if ( zer != 0 and on != 0 ):
        print("NO")
        

    t -= 1 