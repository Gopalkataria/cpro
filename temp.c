// Gopal Kataria

#include <stdio.h>
#include <math.h>
// #include <stdlib.h>
void init()
{
    
#define print(x) printf("%d", x) // print without traling spaces
#define printS(x) printf("%d ", x) // print with a trailing space
#define printL(x) printf("%d\n", x) // print with a trailing endline character
#define input(x) scanf("%d", &x) // input an into a variable

#define fori(i, n) for (i = 0; i < n; i++) // for loop, var i, until n
#define forir(i, n) for (i = n; i > 0; i--) // for loop, var i, from n to 0
#define ford(i, n) for (int i = 0; i < n; i++) // for loop with int declaration
#define fordr(i, n) for (int i = n; i > 0; i--) // reverse for loop with int declatration

#define min(a, b) ((a) < (b) ? (a) : (b)) // min function
#define max(a, b) ((a) > (b) ? (a) : (b)) // max function 
}

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    init();
    int n = 0, x, y, i, j, a = 10;

    // input(n) ;

    // for (x = 0; x < n; x++)
    //     for (y = 0; y < n; y++)
    //         scanf("%d", &grid[x][y]);

    input(x);
    fori(y, x)
    {
        printL(y);
    }
    ford(k, 12) printS(k);
    

    printS(a);
    return 0;
}
