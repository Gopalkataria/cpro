/**
 * C program to create a file and write data into file.
 */

#include <stdio.h>
#include <stdlib.h>

#define DATA_SIZE 1000

int main(int argc, char *argv[])
{
    /* Variable to store user content */
    char data[DATA_SIZE];

    /* File pointer to hold reference to our file */

    FILE *fPtr, *optr;

    /*
     * Open file in w (write) mode.
     * "data/file1.txt" is complete path to create file
     */

    if (argc > 1)
    {
        fPtr = fopen(argv[1], "r");
        optr = fopen(argv[2], "a");
    }
    else
    {
        printf("give %s <filename>\n", argv[0]);
        return 0;
    }

    /* fopen() return NULL if last operation was unsuccessful */
    if (fPtr == NULL || optr == NULL)
    {
        /* File not created hence exit */
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }

    while(fgets(data, DATA_SIZE, fPtr) != NULL)
    {
        fputs(data, optr);
    }

    /* Write data to file */

    /* Close file to save file data */
    fclose(fPtr);

    /* Success message */
    printf("File created and saved successfully. :) \n");

    return 0;
}
