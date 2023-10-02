from itertools import permutations

words = [ "".join(x) for x in permutations(sorted(input())) ]
print( len(words))
print("\n".join(words))