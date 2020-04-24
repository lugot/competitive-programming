#include<stdio.h>
#include<math.h>

int main(){

    int n;
    scanf("%d",&n);

    int p=1;
    int day=1;
    while (n>p){
        p<<=1;
        day++;
    }
    
    printf("%d\n",day);
    
    return 0;
}

