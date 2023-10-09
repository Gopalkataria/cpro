t = int(input())

class nodiv3:
  def __iter__(self):
    self.a = 1
    return self

  def __next__(self):
    x = self.a
    self.a += 1
    if ( self.a % 3) == 0  :
        self.a += 1 
    return x

def sol() :
    x = int(input())
    A = nodiv3() 
    B = nodiv3() 
    for a in A :
        for b in B : 
            c = x-a-b 
            if a > x or b > x : 
                print("NO")
                return 0 
            if c <= 0 :
                continue
            if c%3 != 0 and a != b and b!=c and c!=a  :
                print("YES")
                print(a,b,c)
                return 0 

while ( t != 0  ) :
    sol() 
    t -= 1 

