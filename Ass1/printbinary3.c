#include <stdio.h>

int main() {

	int numr = 0  , num , n=0  ; 
	scanf("%d" , &num ) ; 
	do  {
		numr <<= 1 ; 
		numr +=  ( num & 1)  ;
		num >>= 1  ;
		n++ ; 
	} while ( num != 0 ) ; 
	while( n >0  ) {
		printf("%d" , ( numr & 1))  ; 
		numr >>= 1  ;
		n--; 
	}
	printf("\n") ; 
	return 0 ; 
}
