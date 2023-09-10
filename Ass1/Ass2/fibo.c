#include<stdio.h>
int main(){
    int n,x,y;
    scanf("%d %d %d",&n,&x,&y);
    for(int i=1;i<=n;i++){
        printf("%d ", x);
        int z=x+y;
        x=y;
        y=z;
    }
}