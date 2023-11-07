#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main()
{
    
    Matrix* m = create_matrix(3,3);
    print_matrix(m);
    
    return 0;
}