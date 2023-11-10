#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define bool int
#define true 1
#define false 0

bool isperfect(char *str, int ind, int k)
{
    char c = str[ind];
    if (ind + k >= strlen(str))
        return false;

    for (int i = ind; i < ind + k; i++)
        if (c != str[i])
            return false;

    return true;
}

int main()
{

    int n, k;
    scanf("%d %d", &n, &k);
    char inp[n + 1];
    char debug[k + 1];
    scanf("%s", inp);

    int h = 0;
    if ( n == k ){
        printf("1\n") ; 
        return 0 ; 
    }
    for (int i = 0; i < n;)
    {
        if (i + k > n)
        {
            break;
        }
        if (isperfect(inp, i, k))
        {
            h++;
            i += k;
        }
        else
        {
            i++;
        }
    }

    printf("%d\n", h);

    return 0;
}