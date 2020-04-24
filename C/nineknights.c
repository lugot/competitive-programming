#include<stdio.h>

int search_knight(char b[5][5], int x, int y);
int found_knight(char b[5][5], int x, int y);

int main(){
    char board[5][5];
    char s[5];
    
    for (int i=0; i<5; i++){
        scanf("%s5",s);
        for (int j=0; j<5; j++)
            board[i][j]=s[j];
    }
    int c=0;
    for (int i=0; i<5; i++)
        for (int j=0; j<5; j++)
            if (board[i][j]=='k'){
                c++;
                if (search_knight(board,i,j)){
                    printf("invalid\n");
                    return 0;
                }
            }
    
    if (c!=9){
        printf("invalid\n");
        return 0;
    }
    
    printf("valid\n");
    return 0;
}

//boh, 0=falso, 1=vero
int search_knight(char b[5][5], int x, int y){
    x--; y-=2;
    if (found_knight(b,x,y)) return 1;
    x--; y++;
    if (found_knight(b,x,y)) return 1;
    y+=2;
    if (found_knight(b,x,y)) return 1;
    x++; y++;
    if (found_knight(b,x,y)) return 1;
    x+=2;
    if (found_knight(b,x,y)) return 1;
    x++; y--;
    if (found_knight(b,x,y)) return 1;
    y-=2;
    if (found_knight(b,x,y)) return 1;
    x--; y--;
    if (found_knight(b,x,y)) return 1;
    return 0;
}

int found_knight(char b[5][5], int x, int y){
    if (x>=0 && y>=0 && y<5 && x<5)
        if (b[x][y]=='k') return 1; //true
    return 0; //false
}
