#include<stdio.h>
#include<string.h>

int main(){
    char a[50],b[50];
    
    int n;
    scanf("%d\n",&n);
    
    for (int i=0; i<n; i++){
        scanf("%s\n",&a);
        scanf("%s\n",&b);
        
        for (int j=0; j<strlen(a); j++) printf("%c",a[j]);
        printf("\n");
        for (int j=0; j<strlen(a); j++) printf("%c",b[j]);
        printf("\n");
        
        for (int j=0; j<strlen(a); j++)
            printf(a[j]==b[j] ? "." : "*");
        
        printf("\n\n");
    }
    
    return 0;
}
