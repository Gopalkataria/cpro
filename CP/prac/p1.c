#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define rep(x,lim) for( int x = 0 ; x < lim ; x++ ) 
#define lint long long 

#define min(a, b) ((a) < (b) ? (a) : (b)) // min function
#define max(a, b) ((a) > (b) ? (a) : (b)) // max function 
#define out(x) printf("%d " , x)
#define inp(x) scanf("%d" , &x) 
#define el printf("\n") 

int cmp( const void  * a  , const void * b ) {
    return * ( (int * ) b ) - * ( ( int * ) a )  ; 
}




int main() {

    int n ; 
    inp(n) ; 
    
    int c[n] ; 

    rep( x,n ) inp(c[x]) ; 

    qsort(c , n , sizeof(int) , cmp ) ; 
    
    int s = 0 , k = 0  ; 

    rep( i , n ) {
	k += c[i] ; 
    }
    int a = 0 ; 
    rep( i , n ) {
	s += c[i] ;
	k -= c[i] ; 
	if ( s > k ) {
	    break ;
	    a = i ; 
	}
    }

    out(a) ; 

    return 0 ; 
}
