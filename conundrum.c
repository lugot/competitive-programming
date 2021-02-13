#include<stdio.h>
#include<string.h>

int checkPer(char s[]);

int main(){
    char s[300];
    scanf("%s",s);
    
    int i;
    for (i=0; checkPer(s)!=-1; i++){
        int j=checkPer(s);
        if (j%3==0) s[j]='P';
        if (j%3==1) s[j]='E';
        if (j%3==2) s[j]='R';
    }
    
    printf("%d\n",i);
    return 0;
}

int checkPer(char s[]){
    int i=0;
    for (i=0; i<strlen(s); i++){
        if (i%3==0 && s[i]!='P') return i;
        if (i%3==1 && s[i]!='E') return i;
        if (i%3==2 && s[i]!='R') return i;
    }
    return -1;
}
