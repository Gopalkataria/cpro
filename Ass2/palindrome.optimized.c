// Gopal Kataria
// ECD 2023 112 006
// IIIT Hyderabad

#include <stdio.h>
// #include <math.h>

int main()
{
    int n = 0, mainpos, delta, echeck, ocheck;
    int NUMS[100];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &NUMS[i]);
    int net = n;

    for (mainpos = 1; mainpos < n; mainpos++)
    {
        echeck = ocheck = 1 ;
        for (delta = 0; delta < mainpos; delta++)
        {
            net += ((NUMS[mainpos - delta - 1] == NUMS[mainpos + delta]) ? echeck : (echeck = 0));
            printf("%d %d %d \n", NUMS[mainpos - delta - 1], NUMS[mainpos + delta], echeck);
            net += ((NUMS[mainpos - delta - 1] == NUMS[mainpos + delta + 1]) ? ocheck : (ocheck = 0));
            printf("%d %d %d \n\n", NUMS[mainpos - delta - 1], NUMS[mainpos + delta + 1], echeck);
        }
    }

    printf("%d\n", net);
    return 0;
}
