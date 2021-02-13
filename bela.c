#include<stdio.h>


int main(){
    char d;
    char c[2];
    
    int n,sum=0;
    scanf("%d %c\n",&n,&d);
    
    for (int i=0; i<4*n; i++){
        scanf("%c%c\n",&c[0],&c[1]);
        
        switch(c[0]){
            case 'A':
                sum+=11;
                break;
            case 'K':
                sum+=4;
                break;
            case 'Q':
                sum+=3;
                break;
            case 'J':
                sum+= (c[1]!=d ? 2 : 20);
                break;
            case 'T':
                sum+=10;
                break;
            case '9':
                sum+= (c[1]!=d ? 0 : 14);
                break;
            case '8':
                sum+=0;
                break;
            case '7':
                sum+=0;
                break;
        }        
    }
    
    printf("%d\n",sum);
    return 0;
}

