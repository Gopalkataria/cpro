#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

Matrix *create_matrix(int r, int c)
{
    Matrix *m = (Matrix *)malloc(sizeof(Matrix));
    m->num_rows = r;
    m->num_cols = c;
    m->data = (long long int **)calloc(r, sizeof(long long int *));
    for (int i = 0; i < r; i++)
    {
        m->data[i] = (long long int *)calloc(c, sizeof(long long int));
    }
    return m;
}

void destroy_matrix(Matrix *m)
{
    for (int i = 0; i < m->num_rows; i++)
    {
        free(m->data[i]);
    }
    free(m->data);
    free(m);
}

Matrix *mult_matrix(Matrix *A, Matrix *B)
{
    if (A->num_cols != B->num_rows)
        return NULL;
    Matrix *R = create_matrix(A->num_rows, B->num_cols);
    for (int i = 0; i < A->num_rows; i++)
        for (int j = 0; j < B->num_cols; j++)
        {
            R->data[i][j] = 0;
            for (int c = 0; c < A->num_cols; c++)
                R->data[i][j] += A->data[i][c] * B->data[c][j];
        }
    return R;
}

Matrix *add_matrix(Matrix *A, Matrix *B)
{
    if ((A->num_rows != B->num_rows) || (A->num_cols != B->num_cols))
        return NULL;
    Matrix *R = create_matrix(A->num_rows, B->num_cols);
    for (int i = 0; i < R->num_rows; i++)
        for (int j = 0; j < R->num_cols; j++)
            R->data[i][j] = A->data[i][j] + B->data[i][j];
    return R;
}
Matrix *scalar_mult_matrix(long long int s, Matrix *M)
{
    Matrix *R = create_matrix(M->num_rows, M->num_cols);
    for (int i = 0; i < R->num_rows; i++)
        for (int j = 0; j < R->num_cols; j++)
            R->data[i][j] = M->data[i][j] * s;
    return R;
}
Matrix *transpose_matrix(Matrix *A)
{
    Matrix *R = create_matrix(A->num_cols, A->num_rows);
    for (int i = 0; i < R->num_rows; i++)
        for (int j = 0; j < R->num_cols; j++)
            R->data[i][j] = A->data[j][i];
    return R;
}
long long int determinant(Matrix *M)
{
    if (M->num_cols != M->num_rows)
    {
        return -1;
    }
    if (M->num_cols == 1)
    {
        return M->data[0][0];
    }
    else if (M->num_cols == 2)
    {
        return (M->data[0][0] * M->data[1][1]) - (M->data[1][0] * M->data[0][1]);
    }
    else // recurse
    {
        long long int ans = 0;
        int flag = 1;
        for (int i = 0; i < M->num_rows; i++)
        {
            Matrix *m = create_matrix(M->num_rows - 1, M->num_cols - 1);
            int p = 0;
            for (int j = 0; j < M->num_rows; j++)
            {
                if (j == i)
                    continue;
                else
                {
                    for (int l = 1; l < M->num_cols; l++)
                    {
                        m->data[p][l - 1] = M->data[j][l];
                    }
                    p++;
                }
            }
            ans += flag * (M->data[i][0] * determinant(m));
            flag *= -1;
            destroy_matrix(m);
        }

        return ans;
    }
}
// DO NOT MODIFY THE OUTPUT FORMAT of this function. Will be used for grading
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

Matrix *read_matrix_from_file(char *fname)
{
    FILE *file = fopen(fname, "r");
    if (file == NULL)
        return NULL;
    int n, m;
    fscanf(file, "%d %d", &n, &m);
    Matrix *M = create_matrix(n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            fscanf(file, "%lld", &(M->data[i][j]));
    fclose(file) ;
    return M;
}

int write_matrix_to_file(Matrix *m, char *fname)
{
    FILE *file = fopen(fname, "w");
    if (file == NULL )
        return -1;
    fprintf(file, " %d %d\n", m->num_rows, m->num_cols);
    for (int i = 0; i < m->num_rows; i++)
    {
        for (int j = 0; j < m->num_cols; j++)
        {
            fprintf(file, " %lld ", m->data[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file) ; 
    return 0;
}