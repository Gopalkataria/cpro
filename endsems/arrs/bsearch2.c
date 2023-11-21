#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define rep(x, lim) for (int x = 0; x < lim; x++)
#define lint long long

#define min(a, b) ((a) < (b) ? (a) : (b)) // min function
#define max(a, b) ((a) > (b) ? (a) : (b)) // max function

#define out(x) printf("%d ", x)
#define inp(x) scanf("%d", &x)

int nums[1000] ; 
int k ; 
int func(int x ) { 
    return (nums[x] >= k) ; 
}

int main()
{

    int n;
    inp(n);
    inp(k);

    rep(i, n) inp(nums[i]);

    int x = -1;
    
    // int b = 10 ; 
    for (int b = n; b >= 1; b /= 2)
        while (!func(x+b))
            x += b;

    out(x + 1);

    // while(n--) sol() ;
    return 0;
}
