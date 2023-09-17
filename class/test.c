// Gopal Kataria
// ECD 2023 112 006
// IIIT Hyderabad

#include <stdio.h>
// #include <math.h>

int stacky(int a)
{
    if (a ==0 || a == 1)
    {
        return a ; 
    }
    
   int A = stacky(a - 1);
    printf("%d\n", a);
    int B = stacky(a - 2);
    printf("%d\n", a);

    return A +B ; 

}

int main()
{
    // int n = 0  , x, y;

    // scanf("%d", &n);

    // int grid[n][n] ;

    // for (x = 0; x < n; x++)
    //     for (y = 0; y < n; y++)
    //         scanf("%d", &grid[x][y]);


    stacky(4) ; 


    printf("\n");
    return 0;
}