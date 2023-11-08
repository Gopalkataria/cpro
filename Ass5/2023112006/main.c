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
void print_matrix(Matrix *m)
{
    printf("%d %d\n", m->num_rows, m->num_cols);
    for (int i = 0; i < m->num_rows; i++)
    {
        for (int j = 0; j < m->num_cols; j++)
        {
            printf("%lld ", m->data[i][j]);
        }
        printf("\n");
    }
}
Matrix * read_matrix_from_file( char * fname ){
    FILE * file = fopen(fname , "r") ; 
    int n  , m ; 
    fscanf(file , "%d %d" , &n , &m ) ;
    Matrix *M = create_matrix(n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            fscanf(file, "%lld", &(M->data[i][j]));
    return M;
}

Matrix *read_matrix_from_file(Matrix *  m , char  *fname)
{
    FILE *file = fopen(fname, "w");
    printf("%d %d\n", m->num_rows, m->num_cols);
    for (int i = 0; i < m->num_rows; i++)
    {
        for (int j = 0; j < m->num_cols; j++)
        {
            fprintf(file , "%lld ", m->data[i][j]);
        }
        fprintf(file, "\n");
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
            A = input_matrix();
            B = input_matrix();
            C = mult_matrix(A, B);
            if (C != NULL)
            {
                print_matrix(C);
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
               printf("%lld\n", s) ; 
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