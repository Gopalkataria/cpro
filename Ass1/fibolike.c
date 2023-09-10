#include <stdio.h>

int main() {

	int n,x,y,sum ; 
	scanf("%d %d %d" , &n , &x , &y ) ; 
	if ( n ==1 ) {
	printf("%d" , x ) ;
	} else if( n==2 ) {
	printf("%d %d" , x, y ) ; 
	} else {
		printf("%d %d" , x,y) ;
	       n -= 2 ; 
     		sum = x + y ; 
 		for ( int i = 1 ; i <= n ; i ++ ) {
			printf(" %d" , sum ) ; 
			x = y ; 
			y = sum ; 
			sum = x + y ; 
		} 
	}
	printf("\n") ; 

				



	return 0 ; 
}
