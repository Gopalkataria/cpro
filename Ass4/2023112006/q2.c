#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

// definin a struct to store the complex number
// a n dimentional complex number is basically a vector in n dimensional space
typedef struct complex
{
    int dimension;
    float *coordinates;
} complex;

complex add(complex c1, complex c2)
{
    // inititalize a new complex number and store the sum in it 
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
    // initialize a new complex number and store the difference in it
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
    // calculate the dot product of two complex numbers
    float ans = 0;

    for (int i = 0; i < c1.dimension; i++)
    {
        ans += c1.coordinates[i] * c2.coordinates[i];
    }
    return ans;
}

float mod(complex c1)
{
    // calculate the modulus ( aka magnitude ) of a complex number
    float ans = 0;
    for (int i = 0; i < c1.dimension; i++)
    {
        ans += c1.coordinates[i] * c1.coordinates[i];
    }
    return sqrt(ans);
}

float cosineSimilarity(complex c1, complex c2)
{
    // calculate the cosine similarity of two complex numbers
    // basically its the cos of angles between the two complex vectors
    return dot(c1, c2) / (mod(c1) * mod(c2));
}

void printComplex(complex c)
{
    // print the complex number in the format (a1,a2,a3,....,an)
    printf("Result : ");
    for (int i = 0; i < c.dimension; i++)
    {
        printf("%.2f ", c.coordinates[i]);
    }
    printf("\n");
}
void inputComplex(complex *c, int dimensions)
{
    // initialize a complex number with the given dimensions and input the coordinates
    c->dimension = dimensions;
    c->coordinates = (float *)malloc(dimensions * sizeof(float));
    for (int i = 0; i < c->dimension; i++)
    {
        scanf("%f", &((c->coordinates)[i]));
    }
}

void freeComplexCoordinates(complex* c)
{
    // since we are using malloc for the coordinates we need to free it
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
        // code works assuming that the user will input the complex number and commands in correct format
        // error handling is bare minimum and only for the commands
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
        } else {
            printf("Invalid Command \n");
            continue; // to avoid the below code which frees memory for the coordinates
        }

        // freeing the memory allocated for the coordinates to avoid memory leaks
        freeComplexCoordinates(&c1);
        freeComplexCoordinates(&c2);
    }

    return 0;
}