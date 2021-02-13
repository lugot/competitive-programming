#include<stdio.h>

int X,Y;

int main(){
    scanf("%d %d",&X,&Y);
    
    printf(Y%2==0 ? "possible\n" : "impossible\n");
    
    return 0;
}
