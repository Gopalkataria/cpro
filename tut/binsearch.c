#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {

        scanf("%d", &arr[i]);
    }

    int right = n - 1, mid = 0, left = 0;
    int k = 4, r = -1;

    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (arr[mid] == k)
        {
            r = mid;
            right = mid - 1;
        }
        else if (arr[mid] > k)
            right = mid - 1;
        else
            left = mid + 1;
    }

    printf("%d\n", r);

    return 0;
}