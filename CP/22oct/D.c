#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *line = (int *)calloc(100000001, sizeof(int));
    int n, x, y, flag, max = 0;
    scanf("%d", &n);
    char o;
    for (int i = 0; i < n; i++)
    {

        scanf(" %c %d %d", &o, &x, &y);
        // printf("%c %d %d\n", o, x, y);
        max = max < y ? y : max;

        for (int j = x; j <= y; j++)
        {
            if (o == '+')
            {
                line[j] += 1;
            }
            else if (o == '-')
            {
                line[j] -= 1;
            }
        }

        for (int l = 0; l < 20; l++)
        {
            if (line[l] == 0)
                printf(" ");
            else

                printf("%d ", line[l]);
        }
        printf("\n");
    }

    free(line);
    return 0;
}