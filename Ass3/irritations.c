#include <stdio.h>
#include <stdlib.h>

#define input(x) scanf("%d", &x)
#define print(x) printf("%d\n", x)

#define min(a, b) ((a) < (b) ? (a) : (b)) // min function
#define max(a, b) ((a) > (b) ? (a) : (b)) // max function

void testsolve();
int main()
{
    int tests;
    input(tests);
    for (int x = 0; x < tests; x++)
        testsolve();
    return 0;
}

int n, *MEM, *irrlist;

int irritation(int i)
{
    if (i > n)
    {
        return 0;
    }
    if (MEM[i] = -1)
    {
        MEM[i] = irrlist[i] + irritation(i + irrlist[i]);
    }
    return MEM[i];
}

void testsolve()
{
    input(n);
    MEM = (int *)malloc(sizeof(int) * (n + 1));
    for (int i = 1; i < n + 1; i++)
        MEM[i] = -1;
    irrlist = (int *)malloc(sizeof(int) * (n + 1));
    int irr, maxirr = 0;
    for (int i = 1; i < n + 1; i++)
    {
        input(irrlist[i]);
    }

    for (int i = 1; i < n + 1; i++)
    {
        maxirr = max(irritation(i), maxirr);
    }

    print(maxirr);
}