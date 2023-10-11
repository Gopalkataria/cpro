#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(a, b) ((a) < (b) ? (a) : (b)) // min function
#define max(a, b) ((a) > (b) ? (a) : (b)) // max function
#define prints(x) printf("%s ", x)
#define print(x) printf("%d ", x)
#define I (int)
#define C (char)

int n, k;
char *inp; 
int *tracks ; 

int chardist(char a, char b)
{
    return abs((int)b - (int)a);
}

void fronttrack(int i );  

void backtrack(int i)
{
    k += tracks[i] ;
    inp[i] = C(I inp[i] + tracks[i]);
    tracks[i] = 0 ; 
    if (I inp[i] <= I 'm')
    {
    int step = min(k, chardist(inp[i], 'z'));
    tracks[i] = step;
    inp[i] = C(I inp[i] + step);
    k -= step;
        
    } else {
        fronttrack( i ) ; 
    }
}

void fronttrack(int i)
{
    int step = min( k , chardist(inp[i], 'a')) ; 
    tracks[i] = step ; 
    inp[i] = C (I inp[i] - step )  ;
    k-= step ; 
}

int strdist( char *a  , char * b ){
    int l = strlen(a) , d = 0;
    for (int i = 0; i < l; i++)
    {
            d+= chardist( a[i],b[i]);
    }
    return d ; 

}

int main()
{

    scanf("%d %d", &n, &k);
    inp = (char *)calloc((n+1)*sizeof(char), sizeof(char)) ;
    tracks = (int * )calloc(n * sizeof(int), sizeof(int));
    scanf("%s", inp);

    int maxd = 0;
    for (int i = 0; i < n; i++)
    {
        maxd += max(chardist(inp[i], 'a'), chardist(inp[i], 'z'));
    }
    if (k > maxd)
    {
        printf("-1\n");
        return 0;
    }
    char new[n+1]  ; 
    strcpy(new, inp) ; 
    
    for (int i = 0; i < n; i++)
    {
        fronttrack(i) ; 
        if (k == 0 )
            break; 
    }
    // printf("%s %d \n", inp, 92 - strdist(new, inp));

    if (k!=0)
    for (int i = n-1; i >= 0  ; i--)
    {
        // printf("%s %d \n", inp, 92 - strdist(new, inp));

        backtrack(i) ; 
        if (k==0)
            break;
        
    }
    
    // for (int i = 0; i < n; i++)
    //     print(tracks[i]) ; 
    printf("%s\n",inp) ; 
    

    return 0;
}
