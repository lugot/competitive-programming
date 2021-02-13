#include<stdio.h>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

int main(){
    int a,b,m,sigma,R=0;
    scanf("%d %d\n",&a,&b);
    scanf("%d %d",&m,&sigma);
    
    for (int x=1; x<=MIN((sigma-1)/2,m-1); x++){
        for (int y=MAX(1,sigma-2*x); y<=m-x; y++)
            if (a*x+b*y>R) R=a*x+b*y;
    }
    
    printf("%d\n",R);
    return 0;
}
