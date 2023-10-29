#include <stdio.h>
#include <stdlib.h>
int main( int argc, char *argv[] )
{
    for (int i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]) ; 
    }
    
    printf("First Name : %s\n", argv[1]);
    printf("Last Name : %s\n", argv[2]);
    printf("Age : %s\n", argv[3]);
    return 0;
}
