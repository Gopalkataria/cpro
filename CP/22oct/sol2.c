#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define lint long long int 

void sol()
{
    int n;
    float m, k;
    scanf("%d", &n);
    lint *arr = (lint *)malloc(n * sizeof(lint));
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            k = log2((float)arr[i - 1] / arr[i]);
            k = ceil(k);
            arr[i] *= pow(2, k);
            ans += (int) k;
        }

        // while (arr[i] < arr[i-1])
        // {
        //     arr[i] *= 2 ;
        //     ans++;
        // }
    }
    printf("%d\n", ans);
    free(arr);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        sol();
    }

    return 0;
}