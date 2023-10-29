#include <stdio.h> 


#define print(x) printf("%d\n",x)   

void sol( ){
    int n ; 
    scanf("%d",&n) ;
    int arr[n] ;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]) ;
    }

    if ( n == 2){
        printf("YES") ; 
        return ;
    } 
    
    int f = arr[0] , s  , flag = 0  ;
    for (int x = 0; x < n; x++)
    {
        s = arr[x] + f ; 
        
    }
    



}



int main() {

    int t ; 
    scanf("%d",&t) ;
    while (t--)
    {
        sol() ;
    }
    
}