#include<stdio.h>


int main(){
    int n,m;
    scanf("%d %d",&n,&6 m);
    
    int s[n+m+1];
    for (int i=0; i<n+m+1; i++) s[i]=0;
    
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            s[i+j+2]++;
    
    int max=-1;
    for (int i=0; i<m+n+1; i++)
        if (s[i]>max) max=s[i];
        
    for (int i=0; i<m+n+1; i++)
        if (s[i]==max) printf("%d\n",i);
    return 0;
}
