#include<stdio.h>
#include<math.h>

int main(){
    
    double r,m,c;
    while(1){
        scanf("%lf %lf %lf",&r,&m,&c);
        if (r==0.0) return 0;
        
        double estimated_area= c/m * 4 * r*r;
        printf("%lf %lf\n",M_PI*r*r,estimated_area);
        
        
    }
}
