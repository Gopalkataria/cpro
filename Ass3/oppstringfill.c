#include <stdio.h>
#include <string.h>

#define min(a, b) ((a) < (b) ? (a) : (b)) // min function
#define max(a, b) ((a) > (b) ? (a) : (b)) // max function

#define ps(x) printf("%s -\n", x);
#define pc(x) printf("%c -\n", x);
#define pi(x) printf("%i -\n", x);

int main()
{

    int m, n = 0, k, p;
    scanf("%d %d", &n, &k);
    char inp[n];
    pi(k)
    scanf("%s", inp);
    if (k > (n * 25))
    {
        printf("-1\n");
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        m = min(k, 25);
        p = (int)(inp[i] - 'a');
        p = (p + 26- m) % 26;
        inp[i] = (char)(p + 'a');
        k -= m;

        if (k == 0)
            break;
    }

    printf("%s\n", inp);

    return 0;
}