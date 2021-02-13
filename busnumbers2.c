#include<stdio.h>
#include<math.h>

#define pow3(a) ((a)*(a)*(a))

int is_cube(int n);

int main(){
    int m;
    scanf("%d",&m);
    
    int c[73];
    for (int i=0; i<73; i++) c[i]=pow3(i+1);
    
    int s[73*73];
    int k=0;
    for (int i=0; i<73; i++)
        for (int j=0; j<73; j++)
            s[k++]=c[i]+c[j];
    
    
    for (int i=m; i>0; i--){
        int c=0;
        for (int j=0; j<73*73; j++)
            if (s[j]==i){
                if (c==2){
                    printf("%d\n",i);
                    return 0;
                }
                c++;
            }
    }
    printf("none\n");
    
    return 0;
}
