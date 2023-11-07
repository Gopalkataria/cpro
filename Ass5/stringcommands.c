#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{

    char inp[1000000], c;
    scanf("%s", inp);
    int nquery, q, len;
    len = strlen(inp);
    scanf("%d", &nquery);

    for (int i = 0; i < nquery; i++)
    {
        scanf("%d", &q);
        if (q == 1)
        {
            // reverse(inp, len);
            char temp;
            for (int i = 0; i < len / 2; i++)
            {
                temp = inp[i];
                inp[i] = inp[len - i - 1];
                inp[len - i - 1] = temp;
            }
        }
        else
        {
            scanf("%d %c", &q, &c);
            if (q == 1)
            {
                char new[len + 1];
                strcpy(new, inp);
                strcpy(inp + 1, new);
                inp[0] = c;
                len++;
            }
            else
            {
                inp[len] = c;
                inp[len + 1] = '\0';
                len++;
            }
        }
    }
    printf("%s", inp);

    return 0;
}