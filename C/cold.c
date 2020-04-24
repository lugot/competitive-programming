#include<stdio.h>

int main(){
    int n;
    scanf("%d\n",&n);
    
    int temps[n];
    for (int i=0; i<n; i++) scanf("%d",&temps[i]);
    
    int c=0;
    for (int i=0; i<n; i++)
        if (temps[i]<0) c++;
        
    printf("%d\n",c);
    
    return 0;
}
