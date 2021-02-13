#include<stdio.h>
#include<string.h>

int main(){
    char in[30];
    scanf("%30s",in);
    
    if (strstr(in,"ss"))
        printf("hiss\n");
    else
        printf("no hiss\n");
    
    return 0;
}
