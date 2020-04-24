#include<stdio.h>

double ga1,gb1,ga2,gb2;
double ea1,eb1,ea2,eb2;
double sum_g,sum_e;

int i;

int main(){
    
    scanf("%lf %lf %lf %lf",&ga1,&gb1,&ga2,&gb2);
    scanf("%lf %lf %lf %lf",&ea1,&eb1,&ea2,&eb2);
    
    for(i=0; i<gb1-ga1+1; i++)
        sum_g+=(ga1+i)/(gb1-ga1+1);
    
    for(i=0; i<gb2-ga2+1; i++)
        sum_g+=(ga2+i)/(gb2-ga2+1);
    
    for(i=0; i<eb1-ea1+1; i++)
        sum_e+=(ea1+i)/(eb1-ea1+1);
    
    for(i=0; i<eb2-ea2+1; i++)
        sum_e+=(ea2+i)/(eb2-ea2+1);
    
    if (sum_e>sum_g) printf("Emma\n");
    else if (sum_e<sum_g) printf("Gunnar\n");
    else printf("Tie\n");
    
    return 0;
}
