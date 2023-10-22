#include <stdio.h>
#include <string.h>

int main()
{
    char inp[10001], smin[10001], smax[10001], c;
    scanf("%s", inp);
    strcpy(smin, inp);
    strcpy(smax, inp);
    int k = strlen(inp);
    for (int i = 0; i < k; i++)
    {
        strcpy(smin, strcmp( inp , smin) < 0 ? inp : smin);
        strcpy(smax, strcmp( inp , smax) > 0 ? inp : smax);

        char c = inp[0];
        for (int j = 0; j < k - 1; j++)
        {
            inp[j] = inp[j + 1];
        }
        inp[k - 1] = c;
    }

    printf("%s\n%s\n", smin, smax);
    return 0;
}