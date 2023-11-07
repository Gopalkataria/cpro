#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main()
{
    
    Matrix* m = create_matrix(3,3);
    for (int i = 0; i < m->num_rows; i++)
    {
        for (int j = 0; j < m->num_cols; j++)
        {
            m->data[i][j] = i*3 + j + 1 ; 
        }
        
    }
    int k = determinant(m) ; 
    printf("%d\n", k) ; 
    
    print_matrix(m);
    
    return 0;
}