#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define rep(x, lim) for (int x = 0; x < lim; x++)
#define lint long long

#define min(a, b) ((a) < (b) ? (a) : (b)) // min function
#define max(a, b) ((a) > (b) ? (a) : (b)) // max function


#define out(x) printf("%d ", x)
#define inp(x) scanf("%d", &x)

int nbits(int k)
{
    int c = 0;
    while (k != 0)
    {
        c += k & 1;
        k >>= 1;
    }
    return c;
}

int ans[1000] ;
int na = 0;

void sol(int ini, int n, int k )
{

    if( k  == 0 && n == 0   ){
        ans[na] = ini ; 
        na ++ ; 
        return ; 
    }
    if( n == 0 ){
        return ; 
    }

    sol( ini << 1 , n-1 , k) ; 
    sol( (ini<<1) + 1 , n-1 , k-1 ) ; 

    return;
}

void printbin( int * nums , int x , int  n ) {
    int k = 1 ; 
    rep( i , n ){
	if( k & x ) 
	    out( nums[i] ) ; 
	k<<=1 ; 
    }
    printf("\n")  ;
}

int main()
{

    int n, k;
    inp(n);

    int nums[n];

    rep( i , n ) inp( nums[i] ) ;

    rep( i , 1<<n ) printbin(nums , i ,n) ; 
   

    // while(n--) sol() ;
    return 0;
}
