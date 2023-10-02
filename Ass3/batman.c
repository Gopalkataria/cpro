#include <stdio.h>
#include <stdlib.h>

#define min(a, b) ((a) < (b) ? (a) : (b)) // min function
#define max(a, b) ((a) > (b) ? (a) : (b)) // max function

int N, M, k, **allpaths;
int findpaths(int x, int y)
{
    int i, tl, tr, rt, lt;
    if (x > N || x <= 0 || y > M || y <= 0)
    {
        return 0;
    }
    if (x == 1)
    {
        return 1;
    }

    if (allpaths[x][y] == -1)
    {
        lt = findpaths(x - 2, y - 1);
        rt = findpaths(x - 2, y + 1);
        tl = findpaths(x - 1, y - 2);
        tr = findpaths(x - 1, y + 2);
        allpaths[x][y] = (lt + rt + tl + tr);
    }
    return allpaths[x][y];
}

int main()
{
    scanf("%d %d %d", &N, &M, &k);
    int maxpaths = 0, maxpaths_miny = 1, paths;

    allpaths = (int **)malloc((N + 1) * sizeof(int *));

    for (int x = 1; x <= N; x++)
    {
        allpaths[x] = (int *)malloc((M + 1) * sizeof(int));
        for (int y = 1; y <= M; y++)
            allpaths[x][y] = -1; // default memory val = -1
    }

    for (int i = 0; i < k; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        allpaths[x][y] = 0; // set all forbidden path mem to 0
    }

    for (int y = 1; y <= M; y++)
    {
        paths = findpaths(N, y);
        if (paths > maxpaths)
        {
            maxpaths = paths;
            maxpaths_miny = y;
        }
        else if (paths = maxpaths)
        {
            maxpaths_miny = min(maxpaths_miny, y);
        }
    }

    printf("%d %d\n", maxpaths_miny, maxpaths % 1000000007);

    return 0;
}