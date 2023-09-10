#include <stdio.h>

int main() {
	int inp = 0 , new = 0 ;
       scanf("%d" , &inp ) ; 	
	while ( inp > 0 ) {
		new *= 10 ; 
		new += inp %10 ; 
		inp /= 10 ; 
	}

	printf("%d" , new ) ; 
	return 0 ; 
}

