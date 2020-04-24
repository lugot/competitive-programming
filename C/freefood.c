#include<stdio.h>

int main(){
    int d[366];
    for (int i=0; i<366; i++) d[i]=0;

    int N,s,t;
    scanf("%d\n",&N);
    
    for (int i=0; i<N; i++){
        scanf("%d %d",&s,&t);
        
        for (int j=s; j<=t; j++) d[j]=1;
    }
    
    int counter=0;
    for (int i=0; i<366; i++)
        counter+=d[i];
    
    printf("%d\n",counter);
    
    return 0;
}
