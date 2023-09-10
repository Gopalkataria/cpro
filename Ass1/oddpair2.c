#include <stdio.h>

int main() {

	int n,x,y,z = 0  ; 
	
	scanf("%i" , &n ) ; 

	int nums[n] ;

	for( x = 0 ; x < n ; x ++ ) {
		scanf("%d" , &nums[x] ) ; 
		z ^= nums[x] ; 
	}	
	printf("%d\n" , z ) ; 	

	return 0 ; 
}
