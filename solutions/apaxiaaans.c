#include<stdio.h>
#include<string.h>

int main(){
    char s[251];
    scanf("%s",s);
    
    printf("%c",s[0]);
    for (int i=1; i<strlen(s); i++)
        if (s[i]!=s[i-1]) printf("%c",s[i]);
    
    printf("\n");
    return 0;
}
