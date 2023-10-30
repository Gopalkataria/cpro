#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define debug printf("Here\n");

typedef struct complex
{
    int dimension;
    float *coordinates;
} complex;

complex add(complex c1, complex c2)
{
    complex ans;
    ans.dimension = c1.dimension;
    ans.coordinates = (float *)malloc(c1.dimension * sizeof(float));
    for (int i = 0; i < c1.dimension; i++)
    {
        ans.coordinates[i] = c1.coordinates[i] + c2.coordinates[i];
    }
    return ans;
}
complex sub(complex c1, complex c2)
{
    complex ans;
    ans.dimension = c1.dimension;
    ans.coordinates = (float *)malloc(c1.dimension * sizeof(float));
    for (int i = 0; i < c1.dimension; i++)
    {
        ans.coordinates[i] = c1.coordinates[i] - c2.coordinates[i];
    }
    return ans;
}

float dot(complex c1, complex c2)
{
    float ans = 0;

    for (int i = 0; i < c1.dimension; i++)
    {
        ans += c1.coordinates[i] * c2.coordinates[i];
    }
    return ans;
}

float mod(complex c1)
{
    float ans = 0;
    for (int i = 0; i < c1.dimension; i++)
    {
        ans += c1.coordinates[i] * c1.coordinates[i];
    }
    return sqrt(ans);
}

float cosineSimilarity(complex c1, complex c2)
{
    return dot(c1, c2) / (mod(c1) * mod(c2));
}

void printComplex(complex c)
{
    printf("Result : ");
    for (int i = 0; i < c.dimension; i++)
    {
        printf("%.2f ", c.coordinates[i]);
    }
    printf("\n");
}
void inputComplex(complex *c, int dimensions)
{
    c->dimension = dimensions;
    c->coordinates = (float *)malloc(dimensions * sizeof(float));
    for (int i = 0; i < c->dimension; i++)
    {
        scanf("%f", &((c->coordinates)[i]));
    }
}

void freeComplexCoordinates(complex* c)
{
    free(c->coordinates);
}

int main()
{
    char input[100];

    complex c1, c2 , ans ;
    int n;
    printf("Complex Number Calculator\nEnter Commands \n");
    while (1)
    {
        scanf("%s", input);
        if (strcmp(input, "ADD") == 0)
        {
            scanf("%d", &n);
            inputComplex(&c1, n);
            inputComplex(&c2, n);
            printComplex(add(c1, c2));
        }
        else if (strcmp(input, "SUB") == 0)
        {
            scanf("%d", &n);
            inputComplex(&c1, n);
            inputComplex(&c2, n);
            printComplex(sub(c1, c2));
        }
        else if (strcmp(input, "DOT") == 0)
        {
            scanf("%d", &n);
            inputComplex(&c1, n);
            inputComplex(&c2, n);
            printf("Result : %8.2f \n", dot(c1, c2));
        }
        else if (strcmp(input, "COSINE") == 0)
        {
            scanf("%d", &n);
            inputComplex(&c1, n);
            inputComplex(&c2, n);
            printf("Result : %.2f \n", cosineSimilarity(c1, c2));
        }
        else if (strcmp(input, "-1") == 0)
        {
            printf("Exiting \n");
            return 0;
        }
        freeComplexCoordinates(&c1);
        freeComplexCoordinates(&c2);
    }

    return 0;
}