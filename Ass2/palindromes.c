// Gopal Kataria
// ECD 2023 112 006
// IIIT Hyderabad

#include <stdio.h>
// #include <math.h>

int NUMS[100];

int check_palindrome(int beg, int end)
{
    if ((end - beg) % 2 == 0)
    {
        for (int i = 0; i < (end - beg) / 2; i++)
        {
            if (NUMS[beg + i] != NUMS[end - i])
            {
                return 0;
            }
        }
        return 1;
    }
    else
    {
        for (int i = 0; i < (end - beg + 1) / 2; i++)
        {
            if (NUMS[beg + i] != NUMS[end - i])
            {
                return 0;
            }
        }
        return 1;
    }
}

int main()
{
    int n = 0, x, y;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &NUMS[i]);
    int net = 0;
    for (x = 0; x < n; x++)
        for (y = x; y < n; y++)
            net += check_palindrome(x, y);

    printf("%d\n", net);
    return 0;
}
