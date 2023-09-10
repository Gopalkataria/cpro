#include<stdio.h>
int main(){
    int n,i,j;
    scanf("%d\n",&n);
    int a[n];
    printf("\n"); 
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    int count;
    int ans =0  ; 
    for(i=0;i<n;i++){
       ans ^= a[i];
    }
    printf("%d\n",ans); 
} 