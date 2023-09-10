#include <stdio.h>

int main() {

	int lim , isprime ;
	
	scanf("%d" , &lim ) ; 	
	for ( int num = 2  ; num <= lim ; num ++ ) {
		isprime = 1 ; 
		for ( int x = 2 ; x <= num /2 ; x++ ) {
			if ( num % x == 0 ){
			       isprime = 0 ;
			       break ; 
			}

		} 
		if (isprime ) 
			printf("%d " , num ) ; 
	}
	printf("\n") ; 


	return 0 ; 
}
