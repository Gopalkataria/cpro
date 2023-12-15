#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define rep(x,lim) for( int x = 0 ; x < lim ; x++ ) 
#define lint long long 

#define min(a, b) ((a) < (b) ? (a) : (b)) // min function
#define max(a, b) ((a) > (b) ? (a) : (b)) // max function 
#define out(x) printf("%d " , x)
#define inp(x) scanf("%d" , &x) 
#define el printf("\n") 

#include <string.h> 

int  sol() 
{
    char inp[1000] ; 
    int k = scanf("%s" , inp) ; 
    if ( k != 1 ) return 0 ; 

    int n1 = 0 , n2 = 0 ; 

    int l = strlen( inp )  ; 
    
    rep( i , l ) {
	int k = (int) ( inp[i] - '0' ) ; 
	if( k < 10 && k >  0 )  {
	    n1 = k  ; 
	    break ; 
	}
    }

    rep( i , l ) {
	int k = (int) ( inp[l-i-1] - '0' ) ; 
	if( k < 10 && k >  0 )  {
	    n1 = k  ; 
	    break ; 
	}
    }

    return ( n1 * 10 ) + n2  ; 


} 


int main() {
    

    int n = 1000 ; 
    //inp(n) ; 
    
    int k ; 

    while(n--) { int t =  sol()  ; 
	printf("%d \n" , t ) ; 
	k+= t ; 

    } 

    out(k ) ; 
    return 0 ; 
}
