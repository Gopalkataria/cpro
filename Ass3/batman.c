#include <stdio.h>
#include <stdlib.h>

#define min(a, b) ((a) < (b) ? (a) : (b)) // min function
#define max(a, b) ((a) > (b) ? (a) : (b)) // max function
#define lint long long int 

lint N, M, k, **allpaths;
lint findpaths(lint x, lint y)
{
    lint i, tl, tr, rt, lt;
    if ((x > N) || (x <= 0) || (y > M) || (y <= 0))
    {
        return 0;
    }
    if (x == 1)
    {
        return 1;
    }

       if (allpaths[x][y] == -1)
    {
        lt = findpaths(x - 2, y - 1) % 1000000007;
        rt = findpaths(x - 2, y + 1) % 1000000007;
        tl = findpaths(x - 1, y - 2) % 1000000007;
        tr = findpaths(x - 1, y + 2) % 1000000007;
        allpaths[x][y] = (lt + rt + tl + tr) % 1000000007;
    }
        return (allpaths[x][y] % 1000000007);
}

int main()
{
    scanf("%lld %lld %lld", &N, &M, &k);
    lint maxpaths = 0, maxpaths_miny = 1, paths;

    allpaths = (lint **)malloc((N + 1) * sizeof(lint *));

    for (lint x = 1; x <= N; x++)
    {
        allpaths[x] = (lint *)malloc((M + 1) * sizeof(lint));
        for (lint y = 1; y <= M; y++)
            allpaths[x][y] = -1; // default memory val = -1
    }

    for (lint i = 0; i < k; i++)
    {
        lint x, y;
        scanf("%lld %lld", &x, &y);
        allpaths[x][y] = 0; // set all forbidden path mem to 0
    }

    for (lint y = 1; y <= M; y++)
    {
        paths = findpaths(N, y);
        paths = paths % 1000000007;
        printf("%lld ", paths);
    }

    printf("\n");
    return 0;
}