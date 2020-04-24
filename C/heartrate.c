#include<stdio.h>

int main(){
    int n,b;
    double p;
    scanf("%d\n",&n);
    
    for (int i=0; i<n; i++){
        scanf("%d %lf",&b,&p);
            
        printf("%lf %lf %lf\n", 60/(p/(b-1)) , 60/(p/b) , 60/(p/(b+1)) );
        
        
    }
    
    return 0;
}
