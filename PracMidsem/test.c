#include <stdio.h>
// #include <math.h>
#include <stdlib.h>



int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{

    int k[2][8] = {{9, 3, 4, 2, 19, 32, 15, 1, 2}, {3, 4, 2, 19, 32, 15, 1, 6, 7}};

    //    qsort(k,8, sizeof(int) , cmp ) ;
for (int i = 0; i < 2; i++)
{
    for (int j = 0; j < 8; j++)
    {
        printf("%d ", *(*k+i+j) ) ; 
    }
    

}
    printf("\n %d \n", sizeof(int)); 

    return 0;
}
