#include<stdio.h> 

struct cell{
    int x,y,prev_index;
    
};

int main(){
    int n;
    scanf("%d\n",&n);
    printf("n%d\n",n);
    
    for (int i=0; i<n; i++){
        char syC,eyC;
        int sx,ex;
        scanf("%c %d %c %d\n",&syC,&sx,&eyC,&ex);
        
        int sy=syC-'A';
        int ey=eyC-'A';
        sx=8-sx;
        ex=8-ex;
        
        printf("%d %d %d %d\n",sx,sy,ex,ey);
        
        if ((sx%2==sy%2 && ex%2!=ey%2) ||
            (sx%2!=sy%2 && ex%2==ey%2)){
            printf("Impossible\n");
            continue;
        }
        
        struct cell s[5000];
        int j=0,index=0;
        s[0].x=sx;
        s[0].y=sy;
        s[0].prev_index=-1;
        
        int gx=sx,gy=sy;
        while(1){
            int ggx=gx,ggy=gy;
            
            while(!out_of_bounds(ggx,ggy)){
                s[++j].x=++ggx;
                s[j].y=++ggy;
                s[j].prev_index=index;
            }
            ggx=gx; ggy=gy;
            while(!out_of_bounds(ggx,ggy)){
                s[++j].x=--ggx;
                s[j].y=++ggy;
                s[j].prev_index=index;
            }
            ggx=gx; ggy=gy;
            while(!out_of_bounds(ggx,ggy)){
                s[++j].x=++ggx;
                s[j].y=--ggy;
                s[j].prev_index=index;
            }
            ggx=gx; ggy=gy;
            while(!out_of_bounds(ggx,ggy)){
                s[++j].x=--ggx;
                s[j].y=--ggy;
                s[j].prev_index=index;
            }
            
            for (int k=0; k<j; k++){
                if (s[k].x==gx && s[k].y=gy){
                    
                    
                }
            }
            
            
            
        }
        
    }
    
    
    return 0;
}
int out_of_bounds(int x, int y){
    if (x<0 || x>7 || y<0 || y>8)
        return 1;
    return 0;
}


