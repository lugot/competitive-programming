#include<stdio.h>

int main(){
    int g,s,c;
    scanf("%d %d %d",&g,&s,&c);
    int p=g*3 + s*2 + 1*c;
    
    if (p>=8)
        printf("Province or ");
    else if (p>=5)  
        printf("Duchy or ");
    else if (p>=2)
        printf("Estate or ");
    
    if (p>=6)
        printf("Gold\n");
    else if (p>=3)
        printf("Silver\n");
    else    
        printf("Copper\n");
    
    return 0;
}
