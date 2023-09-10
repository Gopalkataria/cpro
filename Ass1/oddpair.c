#include <stdio.h>

int main() {

	 int i , n ; 
       scanf("%d" , &n) ; 
	int list[n] ; 
	for ( i = 0 ; i < n ; i++ ) 
		scanf("%d" , &list[i] ) ; 
	 int elem , x ; 
	for ( i = 0 ; i < n ; i++ ) {
		elem = list[i] ;
	       if ( elem == 0 ) 
	       		       break ; 
		for ( x = i+1 ; x < n ; x ++ ){
		       if ( elem == list[x] ) {
			       list[i] = 0 ;
			       list[x] = 0 ;
			      break ;  
		       }
		}
	}

	for ( i = 0 ; i <n ; i++ ) {
		if ( list[i] != 0 ) {
		printf("%d\n", list[i] ) ;
	       break ; 
		}
	}



	return 0 ; 
}
