
#include <stdio.h>

#define MAX_INTERVALS 1000

struct Interval
{
    int start;
    int end;
};

int checknonint(struct Interval a[], int n)
{
    if (n == 0 || n == 1)
    {
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].end < a[j].start || a[j].end < a[i].start)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int t;
    scanf("%d", &t);
    struct Interval a[MAX_INTERVALS];
    int n = 0;
    for (int i = 0; i < t; i++)
    {
        char op;
        int x, y;
        scanf(" %c %d %d", &op, &x, &y);
        if (op == '+')
        {
            a[n].start = x;
            a[n].end = y;
            n++;
        }
        else
        {
            for (int j = 0; j < n; j++)
            {
                if (a[j].start == x && a[j].end == y)
                {
                    for (int k = j; k < n - 1; k++)
                    {
                        a[k] = a[k + 1];
                    }
                    n--;
                    break;
                }
            }
        }
        int k = checknonint(a, n);
        printf("%s\n", k ? "NO" : "YES");
    }
    return 0;
}