#include <iostream>

using namespace std;



void sol()
{
    int n , q , query;
    cin >> n >> q;
    int arr[n] ;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int flag = 0;
    for (int i = 0; i < q; i++)
    {
        cin >> query ; 
        int k =  0 ; 
        k = ~k ; 
       k <<= query ; 
       k = ~ k ; 
       for ( int j = 0 ; j < n ; j++)
       cout << (k | ( ~ arr[j])) <<  "\n"; 

    }
    
    
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        sol();
    }
}