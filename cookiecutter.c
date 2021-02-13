#include<stdio.h>
#include<math.h>

struct point{
    double x,y;
};

int main(){
    int n;
    scanf("%d\n",&n);
    
    struct point p[n+1];
    for (int i=0; i<n; i++)
        scanf("%lf %lf\n",&p[i].x,&p[i].y);
    p[n].x=p[0].x; p[n].y=p[0].y;
    
    double target;
    scanf("%lf",&target);
    
    double area=0;
    for (int i=0; i<n; i++)
        area += p[i].x*p[i+1].y - p[i+1].x*p[i].y;
    if (area<0) area*=-1;
    area/=2;
    target= sqrt(target/area);
    
    for (int i=0; i<n; i++){
        double rho=sqrt(p[i].x*p[i].x + p[i].y*p[i].y);
        double theta;
        if (p[i].x==0 && p[i].y==0) theta=0;
        else if (p[i].x>0 && p[i].y>=0) theta=atan(p[i].y/p[i].x);
        else if (p[i].x>0 && p[i].y<0) theta=atan(p[i].y/p[i].x) + 2*M_PI;
        else if (p[i].x<0) theta=atan(p[i].y/p[i].x) + M_PI;
        else if (p[i].x==0 && p[i].y>0) theta=M_PI/2;
        else if (p[i].x==0 && p[i].y<0) theta=-1*M_PI/2;
    
        rho*=target;
        
        p[i].x=rho*cos(theta);
        p[i].y=rho*sin(theta);
    }
    
    double minx=p[0].x, miny=p[0].y;
    for (int i=1; i<n; i++){
        if (p[i].x<minx) minx=p[i].x;
        if (p[i].y<miny) miny=p[i].y;
    }
    if (minx<0) minx*=-1;
    if (miny<0) miny*=-1;
    for (int i=0; i<n; i++){
        p[i].x+=minx;
        p[i].y+=miny;
    }
    
    for (int i=0; i<n; i++)
        printf("%.11lf %.11lf\n",p[i].x,p[i].y);
    
    return 0;
}
