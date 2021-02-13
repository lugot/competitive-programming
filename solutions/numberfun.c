#include<stdio.h>

int main(){
    
    int N;
    scanf("%d",&N);
    
    for (int i=0; i<N; i++){
        double a,b,c;
        scanf("%lf %lf %lf",&a,&b,&c);
        
        if (a+b == c ||
            a-b == c || b-a == c ||
            a*b == c ||
            a/b == c || b/a == c)
            printf("Possible\n");
        else
            printf("Impossible\n");
    }
    
    return 0;
}
