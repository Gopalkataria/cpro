#include <stdio.h>

int main() {

	int bytes[35] , n = 0  , num , numcheck ; 
	scanf("%d" , &num ) ; 
	numcheck = num ; 


	while( num != 0 ) {
		bytes[n] = ( num & 1)  ; 
		num = num >> 1  ; 
		n++ ; 
	}
	while (n > 0 )  {
		n-- ; 
		printf("%d" , bytes[n] ) ; 
	}
      	if ( numcheck == 0 ) 
		printf("0\n" ) ; 
	 else 
	 	printf("\n") ; 	

	return 0 ; 
}
