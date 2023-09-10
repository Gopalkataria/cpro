#include <stdio.h>

int main() {
	
	 int num , x , temp = 0,  ans = 0 ; 
	scanf("%d" , &num) ; 

	for ( x = 0; x < num; x++)
	{
		scanf("%d" , &temp) ; 
		ans ^= temp ; 
	}
	
	printf("%d\n", ans); 

			

	return 0 ; 

}

