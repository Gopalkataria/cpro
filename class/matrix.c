#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix
{
    int num_rows;
    int num_cols;
    float **data;
} Matrix;

Matrix *create_matrix(int r, int c)
{
    Matrix *m = (Matrix *)malloc(sizeof(Matrix));
    m->num_rows = r;
    m->num_cols = c;
    m->data = (float **)calloc(r, sizeof(float *));
    for (int i = 0; i < r; i++)
    {
        m->data[i] = (float *)calloc(c, sizeof(float));
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

Matrix *add_matrix(Matrix *A, Matrix *B)
{
    Matrix * m = create_matrix(A->num_rows, A->num_cols);
    for (int i = 0; i < A->num_rows; i++)
    {
        for (int j = 0; j < A->num_cols; j++)
        {
            m->data[i][j] = A->data[i][j] + B->data[i][j];
        }
    }
    return m;
}

Matrix *mult_matrix(Matrix *A, Matrix *B)
{
    Matrix * m = create_matrix(A->num_rows, B->num_cols);
    for (int i = 0; i < A->num_rows; i++)
    {
        for (int j = 0; j < B->num_cols; j++)
        {
            for (int k = 0; k < A->num_cols; k++)
            {
                m->data[i][j] += A->data[i][k] * B->data[k][j];
            }
        }
    }

}

Matrix *scalar_mult_matrix(float s, Matrix *M)
{
    Matrix * m = create_matrix(M->num_rows, M->num_cols);
    for (int i = 0; i < M->num_rows; i++)
    {
        for (int j = 0; j < M->num_cols; j++)
        {
            m->data[i][j] = s * M->data[i][j];
        }
    }
    return m;
}

void print_matrix(Matrix *m)
{
    for (int i = 0; i < m->num_rows; i++)
    {
        for (int j = 0; j < m->num_cols; j++)
        {
            printf("%f\t", m->data[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    // row size will be provided as the first arg
    // col size will be provided as the second arg
    // remaining row size * column size args will be the entries
    // of the matrix in row major order

    Matrix *m = create_matrix(3, 3);
    print_matrix(m);
    // HW5: write code to create matrix of the dimension provied in first and second arg
    // and initialize it with the values provided as the remaing args

    return 0;
}