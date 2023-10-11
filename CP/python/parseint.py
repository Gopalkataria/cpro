digs = {
    "one" : 1 ,
    "two" : 2 , 
    "three" : 3 ,
    "four" : 4 ,
    "five" : 5 ,
    "six" : 6 ,
    "seven" : 7 ,
    "eight" : 8 ,
    "nine" : 9 
}


tens = {
    "twenty" : 20 ,
    "thirty" : 30 ,
    "forty" : 40 ,
    "fifty" : 50 ,
    "sixty" : 60 ,
    "seventy" : 70 ,
    "eighty" : 80 ,
    "ninety" : 90
}

full = {} 
full["zero"] = 0 
for k , v in digs.items() :
    full[k] = v

full["ten"] = 10
full["eleven"] = 11
full["twelve"] = 12
full["thirteen"] = 13
full["fourteen"] = 14
full["fifteen"] = 15
full["sixteen"] = 16
full["seventeen"] = 17
full["eighteen"] = 18
full["nineteen"] = 19

for k , v in tens.items() :
    full[k] = v
    for m,n in digs.items() :
        full[k + "-" + m] = v + n

def parse_int(string):
    string = string.lower()
    string = " ".join([i for i in string.split(" ") if i != "and"])
    string = string.strip()
    try :
        return full[string]
        
    except KeyError :
        if "million" in string :
            x = string.split("million")
            if len(x) == 1 :
                return 1000000 * parse_int(x[0])
            else :
                return 1000000 * parse_int(x[0]) + parse_int(x[1])
        
        elif "thousand" in string :
            x = string.split("thousand")
            if len(x) == 1 :
                return 1000 * parse_int(x[0])
            else :
                return 1000 * parse_int(x[0]) + parse_int(x[1])
        elif "hundred" in string :
            x = string.split("hundred")
            if len(x) == 1 :
                return 100 * parse_int(x[0])
            else :
                return 100 * parse_int(x[0]) + parse_int(x[1])
        else :
            return 0
    # print( "-" + string + "-\n")
    




print(parse_int(input()))