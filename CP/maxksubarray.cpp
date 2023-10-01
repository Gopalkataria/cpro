#include <iostream>

using namespace std ; 

int main() {
	int n , k ; 
	cin >> n >> k ; 
	int a[n] ; 
	int sum = 0 ; 
	for( int i = 0 ; i < n ; i++ ) {
		cin >> a[i] ; 
		if(i<k) sum += a[i] ; 
	}
	
	for( int x = k ; x < n ; x++ ) 
		sum = max( sum , sum + a[x] - a[x-k] ) ; 

	cout << "\n" << sum ; 
	
	return 0 ; 
}

