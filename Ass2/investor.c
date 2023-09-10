// Gopal Kataria
// ECD 2023 112 006
// IIIT Hyderabad

#include <stdio.h> 

int main() {
	int x = 0 , ones = 0 ; 
	scanf("%d", &x) ; 
	do {
		ones += x & 1 ; 
		x >>= 1 ; 
	}  while (x != 0 ); 
	printf("%d\n" , ones ) ;
	return 0 ; 
}
