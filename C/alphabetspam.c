#include<stdio.h>

int main(){
    int counter=0;
    double wh_ratio=0,lo_ratio=0,up_ratio=0,sy_ratio=0;
    char c;
    
    
    scanf("%c",&c);
    do{
        if (c=='_') wh_ratio++;
        else if (c>=65 && c<=90) up_ratio++;
        else if (c>=97 && c<=122) lo_ratio++;
        else sy_ratio++;
        counter++;
    
        scanf("%c",&c);
    }while(c!='\n');
    printf("%.12lf\n",wh_ratio/counter);
    printf("%.12lf\n",lo_ratio/counter);
    printf("%.12lf\n",up_ratio/counter);
    printf("%.12lf\n",sy_ratio/counter);
    
    
    return 0;
}
