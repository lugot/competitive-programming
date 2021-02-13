#include<stdio.h>

int main(){
        
    int a,b;
    int mixed;
    scanf("%d %d",&a,&b);
    
    do
    {
        mixed=0;
        while (a>=b){
            mixed++;
            a-=b;
        }
        printf("%d %d / %d\n",mixed, a, b);
    
        scanf("%d %d",&a,&b);
    }while(a!=0 && b!=0);
    
    return 0;
}
