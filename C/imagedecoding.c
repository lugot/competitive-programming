#include<stdio.h>
#include<string.h>
#include<math.h>

int main(){
    int n;
    scanf("%d\n",&n);
    
    char s[100000];
    do
    {
        int actual_len=0;
        int err=0;
        
        for (int i=0; i<n; i++){
            fgets(s,100000,stdin);
            char to_print=s[0];
            int length=0;
            
            int iterations;
            int off=2;
            while(sscanf(&s[off],"%d ",&iterations)!=EOF){                
                off+=log(iterations)/log(10)+2;
                
                for (int k=0; k<iterations; k++)
                    printf("%c",to_print);
                
                if (to_print=='#') to_print='.';
                else to_print='#';
                
                length+=iterations;
            }
            printf("\n");
            
            if (i==0) actual_len=length;
            else
                if (length!=actual_len) err=1;
        }
            
        if (err) printf("Error decoding image\n");
        
        scanf("%d\n",&n);
        if (n!=0) printf("\n");
        
    }while(n!=0);
    
    return 0;
}
