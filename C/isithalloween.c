#include<stdio.h>

int main(){
    char m,a,b;
    int d;
    
    scanf("%c%c%c %d",&m,&a,&b,&d);
    if ((m=='O' && d==31) || (m=='D' && d==25)) printf("yup\n");
    else printf("nope\n");
    
    return 0;
}
