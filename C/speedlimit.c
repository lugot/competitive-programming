#include<stdio.h>

int main(){
    int n;
    scanf("%d\n",&n);
    
    do
    {
        int m,h,prev_h=0,miles=0;
        for (int i=0; i<n; i++){
            if (i!=0) prev_h=h;
            scanf("%d %d",&m,&h);

            miles+=m*(h-prev_h);
        }
        printf("%d miles\n",miles);
        
        scanf("%d\n",&n);   
    }while(n!=-1);
    
    return 0;
}
