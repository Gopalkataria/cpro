#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define rep(x,lim) for( int x = 0 ; x < lim ; x++ ) 
#define lint long long 

#define min(a, b) ((a) < (b) ? (a) : (b)) // min function
#define max(a, b) ((a) > (b) ? (a) : (b)) // max function 

#define iffy( i, t , e) ((i) ? (t) : (e) ) 

#define out(x) printf("%d " , x)
#define inp(x) scanf("%d" , &x) 


void merge( int * arr , int left , int mid , int right ) { 

    int i = left , j = mid + 1 ; 
    
    int temp[ right - left + 1 ] ; 
    int t = 0 ; 

    while( i <= mid && j <= right ) {
	if( arr[i] > arr[j] ) {
	    temp[t] = arr[j] ; 
	    j++ ; 
	    t++ ; 
	} else { 
	    temp[t] = arr[i] ; 
	    i++ ; 
	    t++ ; 
	}
    }
    while ( j <= right ) {
	temp[t] = arr[j] ; 
	j++ ; 
	t++ ; 
    }


    while ( i <= mid ) {
	temp[t] = arr[i] ; 
	i++ ; 
	t++ ; 
    }

    for ( int x = left ; x <= right ; x++ ) {
	arr[x] = temp[x-left] ; 
    }    
}



void mergesort( int * arr , int left, int right  ){
    if ( left < right ) {
	int mid = left + ( right - left ) / 2 ; 

	mergesort( arr , left, mid ) ; 
	mergesort( arr , mid+1 , right) ; 

	merge( arr , left  , mid  , right ) ; 
    }
}


int main() {

    int n ; 
    inp(n) ; 
    
    int nums[n] ; 
    rep( i , n ) 
	inp( nums[i] ) ; 

    mergesort(nums , 0 , n-1) ;

    rep(i , n ) 
	out( nums[i] ) ; 


    return 0 ; 
}
