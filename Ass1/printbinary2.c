// new solution using bit shift and masking 


#include <stdio.h>

int main() {

	int  num ; 
	scanf("%d" , &num ) ; 
	int mask = 1 << 30 ; 
	int zer = 0 , x = num ; 
	while ( (x & 1) == 0 && x != 0   ) {
		x >>= 1  ; 
		zer++ ;
	}
	if( num == 0 ) {
		printf("0\n") ; 
		return 0 ; 
	}
	while( !(mask&num) ) {
	       	num &= (~mask) ; 
       	       	num <<= 1 ;
	}
	while( num != 0 ) {
		printf("%d" , ( mask&num ) >>30) ;
	       	num &= (~mask) ; 
       	       	num <<= 1 ;
	}	
	for ( x = 0 ; x  < zer ; x++ ) 
		printf("%d", 0 ) ; 
	printf("\n") ;
	return 0 ; 
}
