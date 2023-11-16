#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "matrix.h"

#define errout printf("ERROR: INVALID ARGUMENT\n");

Matrix *input_matrix(int n)
{
    // printf("fuck")  ;
    Matrix *M = NULL;
    if (n == 0)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        M = create_matrix(n, m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf("%lld", &(M->data[i][j]));
        return M;
    }
    else
    {
        char fname[100];
        scanf("%s", fname);
        M = read_matrix_from_file(fname);

        // print_matrix(M) ;
    }
    return M;
}

void output_matrix(Matrix *M, int n)
{
    if (M == NULL)
    {
        printf("ERROR : INVALID ARGUMENT\n");
        return;
    }
    if (n == 0)
    {
        print_matrix(M);
        return;
    }
    else
    {
        char fname[100];
        // print_matrix(M);
        scanf("%s", fname);
        write_matrix_to_file(M, fname);
    }
}

void log_to_file(char *inp, int n)
{
    FILE *fp = fopen("mx_history", "a");
    if (fp == NULL)
    {
        fp = fopen("mx_history", "w");
        // fprintf(fp, "LOG::history\n");
    }
    fprintf(fp, "LOG::%s %d\n", inp, n);
    fclose(fp);
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
        scanf("%s", inp);
        if (strcmp(inp, "history") == 0)
        {
            FILE *fp = fopen("mx_history", "a");
            fprintf(fp, "LOG::history\n");
            fclose(fp);
            fp = fopen("mx_history", "r");
            char data[1000];
            while (fgets(data, 1000, fp) != NULL)
            {
                printf("%s", data);
            }
            fclose(fp);
        }
        else
            scanf("%d", &n);
        if ((n >> 1) != 0)
        {
            errout;
            continue;
        }

        if (strcmp(inp, "add_matrix") == 0)
        {
            log_to_file(inp, n);
            A = input_matrix(n);
            if (A == NULL)
            {
                errout;
                continue;
            }

            B = input_matrix(n);
            if (B == NULL)
            {
                errout;
                continue;
            }

            C = add_matrix(A, B);
            if (C != NULL)
            {
                output_matrix(C, n);
                destroy_matrix(C);
            }
            else
            {
                errout;
            }
            destroy_matrix(A);
            destroy_matrix(B);
        }
        else if (strcmp(inp, "mult_matrix") == 0)
        {
            log_to_file(inp, n);
            A = input_matrix(n);
            if (A == NULL)
            {
                errout;
                continue;
            }

            B = input_matrix(n);
            if (B == NULL)
            {
                errout;
                continue;
            }
            C = mult_matrix(A, B);
            if (C != NULL)
            {
                output_matrix(C, n);
                destroy_matrix(C);
            }
            else
            {
                errout;
            }
            destroy_matrix(A);
            destroy_matrix(B);
        }
        else if (strcmp(inp, "scalar_mult_matrix") == 0)
        {
            log_to_file(inp, n);
            scanf("%lld", &s);

            A = input_matrix(n);
            if (A == NULL)
            {
                errout;
                continue;
            }
            C = scalar_mult_matrix(s, A);
            output_matrix(C, n);
            destroy_matrix(A);
            destroy_matrix(C);
        }
        else if (strcmp(inp, "transpose_matrix") == 0)
        {
            log_to_file(inp, n);

            A = input_matrix(n);
            if (A == NULL)
            {
                errout;
                continue;
            }
            C = transpose_matrix(A);
            output_matrix(C, n);
            destroy_matrix(A);
            destroy_matrix(C);
        }
        else if (strcmp(inp, "determinant") == 0)
        {
            log_to_file(inp, n);

            A = input_matrix(n);
            if (A == NULL)
            {
                errout;
                continue;
            }

            s = determinant(A);
            if (s != -1)
            {
                printf("%lld\n", s);
            }
            else if (s == -1 && A->num_cols == A->num_rows)
            {
                printf("-1\n");
            }
            else
            {
                errout;
            }
            destroy_matrix(A);
        }
        else if (strcmp(inp, "history") == 0)
            ;
        else
        {
            errout;
        }
    }
    return 0;
}