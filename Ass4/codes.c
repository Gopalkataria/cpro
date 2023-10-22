#include <stdio.h>
#include <string.h>

int main()
{
    int k, flag = 1;
    scanf("%d", &k);
    char c;
    for (int i = 0; i < k; i++)
    {
        scanf(" %c", &c);
        if (c == '"')
            flag = flag ^ 1;

        if (flag && c == ',')
            printf("*");
        else
            printf("%c", c);
    }

    printf("\n");
    return 0;
}
