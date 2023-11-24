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


int main() {

    int n ; 
    inp(n) ; 
    int  m ; 
    inp( m ) ; 

    while( n != 0 ) {
	int t = n ; 
	n = ( m & n ) << 1 ; 
	m = m ^ t ; 
    }
	out(m) ; 
    // while(n--) sol() ; 
    return 0 ; 
}
