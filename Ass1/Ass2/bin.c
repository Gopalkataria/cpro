#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    if(n==0)
    printf("0");
    else{
        int bit[32];
        int size=0;
        while(n>0){
            bit[size++]=(n%2);
            n=n/2;
        }
        for(int i=size-1;i>=0;i--)
        {
            printf("%d",bit[i]);
        }
    }
    return 0;
}