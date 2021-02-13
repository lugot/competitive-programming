#include<stdio.h>

//super generalizzato però boh

int main(){
    int x[3],y[3];
    for (int i=0; i<2; i++) scanf("%d %d\n",&x[i],&y[i]);
    scanf("%d %d",&x[2],&y[2]);
    
    int c[3];
    for (int i=0; i<3; i++) c[i]=0;
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            if (x[i]==x[j]) c[i]++;
    
    int m=2;
    for (int i=0; i<3; i++)
        if (c[i]<m){
            m=i;
            break;
        }
    int x4=x[m];
    
    
    for (int i=0; i<3; i++) c[i]=0;
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            if (y[i]==y[j]) c[i]++;
    
    m=2;
    for (int i=0; i<3; i++)
        if (c[i]<m){
            m=i;
            break;
        }
    int y4=y[m];
    
    printf("%d %d\n",x4,y4);
    
    
    return 0;
}
