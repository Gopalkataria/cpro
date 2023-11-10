#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "matrix.h"



Matrix *input_matrix(int n)
{
    Matrix *M = NULL;
    if (n == 0)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        M = create_matrix(n, m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf(" %lld", &(M->data[i][j]));
        return M;
    }
    else
    {
        char fname[100];
        scanf("%s", fname);
        M = read_matrix_from_file(fname);
        
    }
    return M;
}

void output_matrix ( Matrix * M , int n ){
    if ( n  == 0 ){
        print_matrix(M ) ; 
        return ; 
    } else {
        char fname[100];
        scanf("%s", fname);
        write_matrix_to_file( M , fname) ; 
    }
}

int main()
{

    int q, n;
    long long int s;
    scanf("%d", &q);
    Matrix *A, *B, *C;
    char inp[10000]; // max chars inline = 10000
    // A = input_matrix() ;
    // output_matrix(s, n calar_mult_matrix(9 , A)) ;
    while (q--)
    {
        scanf("%s %d", inp, &n);
        if ((n >> 1) != 0)
        {
            printf("ERROR: INVALID ARGUMENT\n");
            continue;
        }

        if (strcmp(inp, "add_matrix") == 0)
        {
            A = input_matrix(n);
            B = input_matrix(n);
            

            C = add_matrix(A, B);
            if (C != NULL )
            {
                output_matrix(C, n );
                destroy_matrix(C);
            }
            else
            {
                printf("ERROR: INVALID ARGUMENT\n");
            }
            destroy_matrix(A);
            destroy_matrix(B);
        }
        else if (strcmp(inp, "mult_matrix") == 0)
        {
            A = input_matrix(n);
            B = input_matrix(n);
            C = mult_matrix(A, B);
            if (C != NULL)
            {
                output_matrix(C, n );
                destroy_matrix(C);
            }
            else
            {
                printf("ERROR: INVALID ARGUMENT\n");
            }
            destroy_matrix(A);
            destroy_matrix(B);
        }
        else if (strcmp(inp, "scalar_mult_matrix") == 0)
        {
            A = input_matrix(n);
            scanf("%lld", &s);
            C = scalar_mult_matrix(s, A);
            output_matrix(C, n );
            destroy_matrix(A);
            destroy_matrix(C);
        }
        else if (strcmp(inp, "transpose_matrix") == 0)
        {
            A = input_matrix(n);
            C = transpose_matrix(A);
            output_matrix(C, n );
            destroy_matrix(A);
            destroy_matrix(C);
        }
        else if (strcmp(inp, "determinant") == 0)
        {
            A = input_matrix(n);

            s = determinant(A);
            if (s != -1)
            {
                printf("%lld\n", s);
            }
            else
            {
                printf("ERROR: INVALID ARGUMENT\n");
            }
            destroy_matrix(A);
        }
        else
        {
            printf("ERROR: INVALID ARGUMENT\n");
        }
    }
    return 0;
}