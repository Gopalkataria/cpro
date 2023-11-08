#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{

    char *inp = (char *)malloc(sizeof(char) * 1000000), c;
    int start = 500000, end;
    scanf("%s", &inp[start]);
    int nquery, q, len;
    len = strlen(&inp[start]);
    end = start + len;
    int rev = 0;

    scanf("%d", &nquery);

    for (int i = 0; i < nquery; i++)
    {
        scanf("%d", &q);
        if (q == 1)
        {
            rev = rev ^ 1;
            int temp;
            temp = start;
            start = end;
            end = temp;
        }
        else
        {
            scanf("%d %c", &q, &c);
            if (q == 1)
            {
                if (rev)
                {
                    inp[start] = c;
                    start++;
                }
                else
                {
                    start--;
                    inp[start] = c;
                }
            }
            else
            {
                if (rev)
                {
                    end--;
                    inp[end] = c;
                }
                else
                {
                    inp[end] = c;
                    end++;
                }
            }
        }
    }

    if (!(rev))
    {
        for (int i = start; i < end; i++)
        {
            printf("%c", inp[i]);
        }
    }
    else
    {
        for (int i = start - 1; i >= end; i--)
        {
            printf("%c", inp[i]);
        }
    }
    return 0;
}