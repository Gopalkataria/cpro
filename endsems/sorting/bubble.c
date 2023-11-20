#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define rep(x,lim) for( int x = 0 ; x < lim ; x++ ) 
#define lint long long 

#define min(a, b) ((a) < (b) ? (a) : (b)) // min function
#define max(a, b) ((a) > (b) ? (a) : (b)) // max function 

#define iffy( i, t , e) ((i) ? (t) : (e) ) 

#define out(x) printf("%d " , x)
#define inp(x) scanf("%d" , &x) 

void sol() {} 

void swap( int * a , int * b ) {
    *a = *a ^ *b ; 
    *b = *b ^ *a ; 
    *a = *b ^ *a ; 
}

int main() {

    int n ; 
    inp(n) ; 
    
    int nums[n] ; 
    rep(i , n ) inp( nums[i] ) ; 

    rep( i , n ) 
	rep( j , n-1) 
	if(nums[j] > nums[j+1] ) 
	    swap( &nums[j] , &nums[j+1] ) ; 
    
    rep( i , n ) out( nums[i] ) ; 

    // while(n--) sol() ; 
    return 0 ; 
}
