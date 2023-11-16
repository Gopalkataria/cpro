#include <stdio.h> 

int main() {
    int n ; 
    scanf(" %d", &n) ; 

    int * nums ; 
    nums = ( int *) calloc( 1000000001 , sizeof(int)) ; 
    int temp = 0 ; 
    for ( int i = 0 ; i < n ; i ++ ){
        scanf(" %d", &temp ) ; 
        nums[temp] = 1 ; 
    }
    temp = 0 ; 
    for (int i = 0; i <  1000000001 ; i ++) 
    {
       temp += nums[i] ; 
    }
    printf("%d" , temp ); 


}