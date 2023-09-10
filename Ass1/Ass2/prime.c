#include<stdio.h>
#include<math.h>
int main(){
    int n,i,j;
    scanf("%d",&n);
    
    for(i=2;i<=n;i++){
       int flag=0;
        for(j=2;j<=sqrt(i);j++){
            if(i%j==0){
                flag++;
                break;
            }
        }
        if(flag==0)
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}