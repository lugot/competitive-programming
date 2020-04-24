#include<stdio.h>
#include<string.h>

int main(){
    char s[15000];
    scanf("%s",s);
    
    int a=0,b=0;
    for (int i=0; i<strlen(s); i++){
        if (i<strlen(s)/2)
            a+=(int)s[i]-65;
        else
            b+=(int)s[i]-65;
    }
    
    for (int i=0; i<strlen(s); i++){
        int c=s[i];
        if (i<strlen(s)/2) c+=a;
        else c+=b;
        
        while(c>90) c-=26;
        s[i]=c;
    }
    
    char s1[15000/2];
    for (int i=0; i<strlen(s)/2; i++){
        int c=s[i]+s[i+ strlen(s)/2]-65;

        while (c>90) c-=26;
        s1[i]=c;
    }
    printf("%s\n",s1);
    
    return 0;
}
