2147483647 2147483647 #include<stdio.h>

	int width, height;
void row( char c , char v ) {
	if ( width == 1 ) {
		printf("%c\n" , c ) ; 
	} else if ( width == 2 ) {
		printf("%c%c\n" , c,c ) ; 
	} else {
		
		printf("%c" , c ) ; 
		for ( int i = 0 ; i < width - 2 ; i++ ) 
			printf("%c" , v ) ; 
		
		printf("%c\n" , c ) ; 
	}
}
			


int main() {

 	scanf("%d %d", &width , &height ) ; 
	if( height == 1 ) {
		row('o','-' );
	} else if ( height == 2 ) {
		row('o','-' ); 
		row('o','-' ); 
	} else {
		row('o','-' ); 
		for ( int i = 0 ; i < height-2 ; i++ )
			row('|' , ' ' ) ; 
		row('o','-' ); 
	} 



	return 0 ; 
}
