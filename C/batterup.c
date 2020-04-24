#include<stdio.h>

int main(){
    int n;
    scanf("%d\n",&n);
    
    double p=0;
    int c=0;
    for (int i=0; i<n; i++){   
        int b;
        scanf("%d",&b);
        
        if (b==-1) continue;
        p+=b;
        c++;
    }
    
    printf("%lf\n",p/c);
    return 0;
}
