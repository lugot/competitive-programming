#include<stdio.h>
#include<string.h>
#include<math.h>

int is_square_of(int n);

int main(){
    
    int n;
    scanf("%d",&n);
    
    for (int i=0; i<n; i++){
        char s[10000];
        scanf("%s",&s);
        
        int length = strlen(s);
        int jump = (int) sqrt((double)length);
        
        int index=0;
        for (int j=0; j<jump; j++){
            index=jump-j-1;
            
            while(index<length){
                printf("%c",s[index]);
                index+=jump;
            }
        }
        printf("\n");
    }
    
    return 0;
}
