// Gopal Kataria
// ECD 2023 112 006
// IIIT Hyderabad

#include <stdio.h>

int main()
{
    int n = 0, x = 1;
    scanf("%d", &n);
    for (x = 1; x * x <= n; x++)
        printf("%d ", x * x);
    printf("\n");
    return 0;
}