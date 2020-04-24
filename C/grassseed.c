#include<stdio.h>

int main(){
    double C,w,l,cost=0;
    int L;
    scanf("%lf\n",&C);
    scanf("%d\n",&L);
    
    for (int i=0; i<L; i++){
        scanf("%lf %lf",&w,&l);
        cost+= (w*l)*C;
        
    }
    printf("%lf\n",cost);
    
    return 0;
}
