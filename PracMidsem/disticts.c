#include <stdio.h>
// #include <math.h>

int main()
{
    int n = 0, x, y;

    scanf("%d", &n);
    int count = 0;

    int nums[n];

    for (int i = 0; i < n; i++)
    {
        int curr;
        scanf("%d", &curr);
        nums[i] = curr;
        count++;
        for (int j = 0; j < i; j++)
        {
            if (curr == nums[j])
            {
                count--;
                break;
            }
        }
    }

    // int grid[n][n] ;

    // for (x = 0; x < n; x++)
    //     for (y = 0; y < n; y++)
    //         scanf("%d", &grid[x][y]);

    printf("%d \n", count);
    return 0;
}
