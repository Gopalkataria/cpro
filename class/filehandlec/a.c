#include <stdio.h>
#include <stdlib.h>

#define DATA_SIZE 1000

int main(int argc, char *argv[])
{
    FILE * file = fopen("ff", "r") ;
    char * c = (char * )malloc(100* sizeof(char)) ; 
    fgets( c , 100 , file  ); 
    printf("%s" , c) ; 
    fclose(file)  ;  
    return 0;
}