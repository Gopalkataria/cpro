#include <stdio.h>
#include <stdlib.h>

int dist( char a , char b ){
    return  abs((int)(b-a)) ; 
}

int main() {

    int n , k ; 
    scanf("%d %d", &n , &k) ; 
    char inp[n+1] ; 
    scanf("%s" , inp) ; 

    if (k > n*25)
    {
        printf("-1\n") ; 
        return 0 ; 
    }
    for (int i = 0; (i < n ) ; i++)
    {
        int d = dist( inp[i] , 'a')  ;
        // printf("\n%d %d %d ", inp[i], d, k);
        if ( d < k )
        {
            inp[i] = (char) ( (int)inp[i] - d )  ; 
            k-= d ; 
        } else if (d > k )
        {
            inp[i] = (char)((int)inp[i] - k);
            k = 0 ;

        }
        // printf("\n%d %d %d ", inp[i], d, k);
        
    }
    for (int i = n-1 ; (i > -1); i--)
    {
        int d = dist(inp[i], 'z');
        // printf("\n%d %d %d ", inp[i], d, k);
        if (d < k)
        {
            inp[i] = (char)((int)inp[i] + d);
            k -= d;
        }
        else if (d > k)
        {
            inp[i] = (char)((int)inp[i] + k);
            k = 0;
        }
        // printf("\n%d %d %d ", inp[i], d, k);
    }

    printf("%s\n", inp) ; 
    
    

    return 0 ; 
}