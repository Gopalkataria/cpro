#include <stdio.h>
#include <math.h>
#include <string.h>

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
    for (int i = 0; i < c.dimension; i++)
    {
        printf("%f ", c.coordinates[i]);
    }
    printf("\n");
}
void inputComplex(complex *c, int dimensions)
{
    c->dimension = dimensions;
    for (int i = 0; i < c->dimension; i++)
    {
        scanf(" %f", &c->coordinates[i]);
    }
}

int main()
{
    char input[100];
    while (1)
    {

        complex c1, c2;
        int n;
        fgets(input, 100, stdin);

        if (strcmp(input, "-1\n") == 0)
        {
            return 0;
        }
        sscanf(input, "%s %d", input, &n);
        inputComplex(&c1, n);
        if (input[0] == 'M')
        {
            printf("%f\n", mod(c1));
            continue;
        }
        inputComplex(&c2, n);

        if (input[0] == 'A')
        {
            printComplex(add(c1, c2));
        }
        else if (input[0] == 'S')
        {
            debug ; 

            printComplex(add(c1, c2));
        }
        else if (input[0] == 'D')
        {
            printf("%f\n", dot(c1, c2));
        }

        else if (input[0] == 'C')
        {
            printf("%f\n", cosineSimilarity(c1, c2));
        }
    }

    return 0;
}