// Gopal Kataria 
// ECD 2023 112 006 
// IIIT Hyderabad


#include <stdio.h>

int main()
{

    int n, x, y, D;
    scanf("%d", &n);

    int grid[n][n];
    for (x = 0; x < n; x++)
        for (y = 0; y < n; y++)
            scanf("%d", &grid[x][y]);

    int corn = grid[0][0];
    scanf("%d", &D);
    if (D)
    {
        for (x = 0; x < n - 1; x++)
        {
            grid[x][0] = grid[x + 1][0];
        }
        for (y = 0; y < n - 1; y++)
        {
            grid[n - 1][y] = grid[n - 1][y + 1];
        }
        for (x = n - 2; x >= 0; x--)
        {
            grid[x + 1][n - 1] = grid[x][n - 1];
        }
        for (y = n - 2; y >= 0; y--)
        {
            grid[0][y + 1] = grid[0][y];
        }
        grid[0][1] = corn;
    }
    else
    {
        for (y = 0; y < n - 1; y++)
        {
            grid[0][y] = grid[0][y + 1];
        }
        for (x = 0; x < n - 1; x++)
        {
            grid[x][n - 1] = grid[x + 1][n - 1];
        }
        for (y = n - 2; y >= 0; y--)
        {
            grid[n - 1][y + 1] = grid[n - 1][y];
        }
        for (x = n - 2; x >= 0; x--)
        {
            grid[x + 1][0] = grid[x][0];
        }
        grid[1][0] = corn;
    }
    for (x = 0; x < n; x++)
    {
        for (y = 0; y < n; y++)
            printf("%d ", grid[x][y]);
        printf("\n");
    }

    return 0;
}