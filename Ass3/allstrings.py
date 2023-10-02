from itertools import permutations

inp = input()
words = [ "".join(x) for x in permutations(inp) ]
words.sort()

print( len(words))
for word in words :
    print(word)