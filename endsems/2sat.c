#include <stdio.h>
#include <string.h>

int operate(int a, int b, int op)
{
    switch (op)
    {
    case 0:
        return (a | b) & 1;
    case 1:
        return (~a | b) & 1;
    case 3:
        return (~a | ~b) & 1;
    case 2:
        return (~b | a) & 1;
    default:
        return -1;
    }
}

int main()
{
    char inp[100];

    char opn[100][3];

    int n, v;

    scanf(" %d %d", &n, &v);
    printf("input without any spaces\n");
    scanf("%s", inp);
    int count = 0;
    char *tok = strtok(inp, ".");
    while (tok != NULL)
    {
        int a, b, op;
        if (tok[2] == '\'')
        {
            if (tok[5] == '\'')
            {
                a = (int)(tok[1] - 'a');
                b = (int)(tok[4] - 'a');
                op = 3;
            }
            else
            {
                a = (int)(tok[1] - 'a');
                b = (int)(tok[4] - 'a');
                op = 1;
            }
        }
        else
        {
            if (tok[4] == '\'')
            {
                a = (int)(tok[1] - 'a');
                b = (int)(tok[3] - 'a');
                op = 2;
            }
            else
            {
                a = (int)(tok[1] - 'a');
                b = (int)(tok[3] - 'a');
                op = 0;
            }
        }
        opn[count][0] = a;
        opn[count][1] = b;
        opn[count][2] = op;
        count++;
        tok = strtok(NULL, ".");
    }
    for (int x = 0; x < count; x++)
    {
        printf("%d %d %d\n", opn[x][0], opn[x][1], opn[x][2]);
    }

    for (int i = 0; i < (1 << n); i++)
    {
        int ans = 1;
        for (int x = 0; x < count; x++)
        {
            ans &= operate(i >> opn[x][0] , i >> opn[x][1] , opn[x][2])  ; 
        }
        if( ans ) {
            printf("\n") ; 
            for (int j = 0; j < n; j++)
            {
            printf("%c=%d; ", (char) (j + 'a') ,( i >> j ) & 1 ) ; 
                
            }
            printf("\n");

            break ; 
        }
    }

    return 0;
}