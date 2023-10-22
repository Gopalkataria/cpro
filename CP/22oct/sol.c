#include <stdio.h>
#include <stdlib.h>

void sol()
{
    int a, b, c, d;
    scanf("%1d%1d%1d%1d", &a, &b, &c, &d);
    a = a == 0 ? 10 : a;
    b = b == 0 ? 10 : b;
    c = c == 0 ? 10 : c;
    d = d == 0 ? 10 : d;

    int ans = 4 + abs(1 - a) + abs(a - b) + abs(b - c) + abs(c - d);
    printf("%d\n", ans);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        sol();
    }

    return 0;
}