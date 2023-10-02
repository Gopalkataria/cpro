#include <stdio.h>
#include <string.h>

#define debug(x) \
    {            \
    }
// #define debug(x) printf(" %d ", x)

int main()
{

    char inp[60];
    scanf("%s", inp);

    int n = strlen(inp);
    int unique = 1, up = 0, low = 0;
    for (int i = 0; i < n; i++) // check if all characters are unique
        for (int j = 0; j < n; j++)
            if (inp[i] == inp[j] && i != j)
            {
                debug(inp[i]);
                unique = 0;
                break;
            }

    for (int i = 0; i < n; i++) // check if at least one is lowercase
        if (((inp[i] - 'a') < 26) && (inp[i] > 91))
        {
            low = 1;
            break;
        }

    for (int i = 0; i < n; i++) // check if at least one is uppercase
        if ((inp[i] - 'A') < 26)
        {
            up = 1;
            break;
        }

    if (up & low & unique)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }

    return 0;
}