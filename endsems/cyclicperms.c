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

int *nums;

int sol(int index, int val, int n)
{
    if (nums[index] == val)
        return 1;

    if (n == 0)
        return 0;

    return sol(nums[index], val, n - 1);
}

void clear(int i)
{
    int t = nums[i];
    if (t != 0)
    {
        nums[i] = 0;
        clear(t);
    }
}

int main()
{
    int n;
    inp(n);
    nums = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++)
    {
        scanf(" %d", &nums[i]);
    }

    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if( nums[i] == 0 ) continue; 
        
        int k = sol(i, i, n);
        if (k)
        {
            count++;
            clear(i);
        }
    }

    out(count);

    free(nums);
    return 0;
}
