#include <stdio.h>
#include <time.h>

#define inp(x) scanf(" %d", &x)
#define out(x) printf("%d ", x);
#define rep(i, n) for (int i = 0; i < n; i++)

int random(int *k)
{
    *k |= (*k << 15);
    *k ^= (*k >> 13);
    *k ^= (*k << 7);
    *k &= ~(1 << 31);
    return *k;
}

int main()
{

    int s = time(NULL);
    int net = 1 << 30;

    int nums[10] = {0};

    rep(i, net)
    {
        int k = random(&s);
        nums[k % 10] += 1;
    }

    rep(i, 10) printf("%f ", (((float)nums[i]) / net));
    return 0;
}