#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define rep(x, lim) for (int x = 0; x < lim; x++)
#define lint long long

#define min(a, b) ((a) < (b) ? (a) : (b)) // min function
#define max(a, b) ((a) > (b) ? (a) : (b)) // max function
#define out(x) printf("%d ", x)
#define inp(x) scanf("%d", &x)
#define el printf("\n")

void sol() {}

int main()
{

    int n;
    inp(n);

    int nums[n];
    int k;
    inp(k);
    rep(i, n) inp(nums[i]);

    for(lint i = 0  ; i < ( 1 << n )  ; i++ )
    {
        if (__builtin_popcount(i) == k)
        {
            rep(j, n)
            {
                if ((1ll << j) & i)
                {
                    out(nums[j]);
                }
            }
            el;
        }
    }

    // while(n--) sol() ;
    return 0;
}
