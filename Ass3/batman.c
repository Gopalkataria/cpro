#include <stdio.h>
#include <stdlib.h>

#define min(a, b) ((a) < (b) ? (a) : (b)) // min function
#define max(a, b) ((a) > (b) ? (a) : (b)) // max function

int N, M, k, **forbiddenpaths, **allpaths;
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
    for (int i = 0; i < k; i++)
    {
        if (forbiddenpaths[i][0] == x && forbiddenpaths[i][1] == y)
        {
            return 0;
        }
    }
    if (allpaths[x][y] == -1)
    {
        lt = findpaths(x - 2, y - 1);
        rt = findpaths(x - 2, y + 1);
        tl = findpaths(x - 1, y - 2);
        tr = findpaths(x - 1, y + 2);
        // printf("\n%d %d %d \n" , x,y,lt+tr+rt+tl) ;
        allpaths[x][y] =  (lt + rt + tl + tr);
        // return (lt + rt + tl + tr);
    }
    return allpaths[x][y];
}

int main()
{
    scanf("%d %d %d", &N, &M, &k);
    int maxpaths = 0, maxpaths_miny = 1, paths;

    forbiddenpaths = (int **)malloc(k * sizeof(int *));
    allpaths = (int **)malloc((N+1) * sizeof(int *));

    for (int x = 1; x <= N; x++)
    {
        allpaths[x] = (int *)malloc((M+1) * sizeof(int)); 
        for (int y = 1; y <= M; y++)
        {
            allpaths[x][y] = -1 ; 
        }
        
    }
    

    for (int i = 0; i < k; i++)
    {
        forbiddenpaths[i] = (int *)malloc(2 * sizeof(int));
        scanf("%d %d", forbiddenpaths[i], forbiddenpaths[i] + 1);
        // printf("%d %d", *forbiddenpaths[i], *(forbiddenpaths[i] + 1));
    }

    for (int y = 1; y <= M; y++)
    {
        paths = findpaths(N, y);
        // printf("%d %d . \n", paths, y);
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

    printf("%d %d", maxpaths_miny, maxpaths);

    // for (int x = 0; x < N; x++)
    // {
    //     printf("\n"); 
    //     for (int y = 0; y < M; y++)
    //     {
    //         printf("%d  ", findpaths(x + 1, y + 1));
    //         // printf("%d  for %d , %d\n " , findpaths(x+1, y+1), x+1 , y+1);
    //     }
        
    // }
    printf("\n");

    return 0;
}