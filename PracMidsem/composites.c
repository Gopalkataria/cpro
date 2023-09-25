#include <stdio.h>
// #include <math.h>

int isprime(int n)
{

    for (int i = 2; i < n; i++) if (n % i == 0) return 0;
    return 1;
}

int main()
{
    int n = 0, x, y;

    x = scanf("%d", &n);
    int comp = 2;

    for (int i = 0; i < n; i++)
    {
        comp++;
        while (isprime(comp))
            comp++;
    }

    printf("f %2.7d\n", comp);
    return 0;
}
