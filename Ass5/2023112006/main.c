#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "matrix.h"

Matrix *input_matrix()
{
    int n, m;
    scanf("%d %d", &n, &m);
    Matrix *M = create_matrix(n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf(" %lld", &(M->data[i][j]));
    return M;
}

int main()
{

    int q, n;
    long long int s;
    scanf("%d", &q);
    Matrix *A, *B, *C;
    char inp[10000]; // max chars inline = 10000
    // A = input_matrix() ; 
    // print_matrix(scalar_mult_matrix(9 , A)) ; 
    while (q--)
    {
        scanf("%s %d", inp, &n);
        if (strcmp(inp, "add_matrix") == 0)
        {
            A = input_matrix();
            B = input_matrix();
            C = add_matrix(A, B);
            if (C != NULL)
            {
                print_matrix(C);
            }
            else
            {
                printf("ERROR: INVALID ARGUMENT");
            }
            destroy_matrix(A);
            destroy_matrix(B);
            destroy_matrix(C);
        }
        else if (strcmp(inp, "mult_matrix") == 0)
        {
            A = input_matrix();
            B = input_matrix();
            C = mult_matrix(A, B);
            if (C != NULL)
            {
                print_matrix(C);
            }
            else
            {
                printf("ERROR: INVALID ARGUMENT");
            }
            destroy_matrix(A);
            destroy_matrix(B);
            destroy_matrix(C);
        }
        else if (strcmp(inp, "scalar_mult_matrix") == 0)
        {
            A = input_matrix();
            scanf("%lld", &s);
            C = scalar_mult_matrix(s, A);
            print_matrix(C);
            destroy_matrix(A);
            destroy_matrix(C);
        }
        else if (strcmp(inp, "transpose_matrix") == 0)
        {
            A = input_matrix();
            C = transpose_matrix(A);
            print_matrix(C);
            destroy_matrix(A);
            destroy_matrix(C);
        }
        else if (strcmp(inp, "determinant") == 0)
        {
            A = input_matrix();
            s = determinant(A);
            if (s != -1)
            {
                print_matrix(C);
            }
            else
            {
                printf("ERROR: INVALID ARGUMENT");
            }
            printf("%lld\n", s);
            destroy_matrix(A);
        }
        else
        {
            printf("ERROR: INVALID ARGUMENT");
        }
    }
    return 0;
}