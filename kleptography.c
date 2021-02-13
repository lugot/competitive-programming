#include<stdio.h>
#include<string.h>

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    
    char key[n];
    char text[m];
    scanf("%sn%sm",key,text);
    
    printf("%s%s",key,text);
    
    int chip[m];
    for (int i=0; i<m; i++){
        chip[0]=key[n]-97;
    }
        
    return 0;
}
