#include<stdio.h>

int main(){
    int X,Y,N;
    scanf("%d %d %d",&X,&Y,&N);
    
    for (int i=1; i<=N; i++){
        if (i!=1) printf("\n");
        if (i%X==0) printf("Fizz");
        if (i%Y==0) printf("Buzz");
        if (i%X!=0 && i%Y!=0) printf("%d",i);
    }
    
    printf("\n");
    
    return 0;
}
