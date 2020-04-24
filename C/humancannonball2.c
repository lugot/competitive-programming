#include<stdio.h>
#include<math.h>

int main(){
    int n;
    scanf("%d\n",&n);
    
    double v0,theta,x1,h1,h2;
    for (int i=0; i<n; i++){
        scanf("%lf %lf %lf %lf %lf",&v0,&theta,&x1,&h1,&h2);
        
        double t=x1/(v0*cos(theta*M_PI/180.0));
        double y=v0*t*sin(theta*M_PI/180.0) - 0.5*9.81*t*t;
        
        if (y>h1+1 && y<h2-1)
            printf("Safe\n");
        else
            printf("Not Safe\n");
    }
    
    return 0;
}
