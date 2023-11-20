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

int cmp( const void * a  , const void * b ) {
    return ( *(int * ) a - *(int *) b )  ; 
}



int main() {

    int n , k  ; 
    inp(n) ; 
    inp(k) ; 
    int nums[n] ; 

    rep( i ,  n ) 
    inp( nums[i]) ; 
    
    qsort(nums, n , sizeof(int) , cmp ) ; 
    int *  m = (int *  ) bsearch( &k , nums , n , sizeof(int) , cmp  ) ; 

    int f = (int) (m - nums ) ; 

    // while (nums[f-1] == k )
    // {
    //     f -- ; 
    // }
    

    printf("%d %d ", * m  , f ) ; 

    



    return 0 ; 
}
