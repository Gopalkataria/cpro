#include <iostream>
#include <math.h>

using namespace std;



int main() {
    // Your code here
    int nhouses , nclients, delta ; 
    cin >> nhouses >> nclients >> delta ; 

    int houses[nhouses] , clients[nclients] ;

    for (int i = 0; i < nhouses; i++)
    {
        cin >> houses[i];
    }

    for (int i = 0; i < nclients; i++)
    {
        cin >> clients[i];
        int f = 1 ;
        for (int j = 0; j < nhouses; j++)
        {
            if( abs(houses[j] - clients[i] ) <= delta ){
            f = 0 ; 
            }
        }

        if ( f ) {
            clients[i] = -1  ; 
        }
        
    }

    return 0;
}
