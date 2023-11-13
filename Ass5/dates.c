#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define bool int
#define true 1
#define false 0

bool isperfect(char *str, int k , char c )
{
    for (int i = 0; i < k; i++)
        if (c != str[i])
            return false;

    return true;
}

int main()
{

    int n, k;
    scanf(" %d %d", &n, &k);
    char inp[n + 1];
    char window[k + 1];
    scanf(" %s", inp);

    if (n == k)
    {
        printf("1\n");
        return 0;
    }
    if (k == 0)
    {
        printf("0\n");
        return 0;
    }
    int max = 0;
    for (char c = 'a'; c <= 'z'; c++)
    {
        int h = 0;
        for (int i = 0; i < n;)
        {
            strncpy(window, inp + i, k);
            // printf("%s  " , window  ) ;
            if (isperfect(window, k , c ))
            {
                i = i + k;
                h++;
            }
            else
            {
                i++;
            }
        }
        max = h > max ? h : max ; 
    }

    printf(" %d", max );

    return 0;
}