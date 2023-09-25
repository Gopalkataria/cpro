#include <stdio.h>

int main()
{
    int arr[5] = {13, 45, 67, 19, 11};

    int i;

    int(*ptr)[5];

    ptr = &arr;

    for (i = 0; i < 5; i++)
    {
        printf("%d ", *(*ptr + i));
    }

    printf("\n");

    return 0;
}