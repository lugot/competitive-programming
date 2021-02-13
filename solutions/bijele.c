#include<stdio.h>

int main(){

    int target[] = {1,1,2,2,2,8};
    
    int num_piece;
    for (int i=0; i<6; i++){
        scanf("%d",&num_piece);
        
        printf("%d ",(target[i]-num_piece));
    }
    printf("\n");
        
    return 0;
}
