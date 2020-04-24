#include<stdio.h>

struct combination{
    int value;
    int a,b,c;
};

void print_combination(int x, int p[]);

int main(){
    int n;
    scanf("%d",&n);
    
    if (n==0){
        printf("impossible");
        return 0;
    }
    
    int p[61];
    for (int i=0; i<60; i++){
        if (i<20) p[i]=(20-i)*3;
        else if (i>=20 && i<40) p[i]=p[i-20]/3*2;
        else p[i]=p[i-20]/2;
    }
    p[60]=0;
    
    struct combination l[61*61*61];
    int l_index=0;
    for (int i=0; i<61; i++)
        for (int j=0; j<61; j++)
            for (int k=0; k<61; k++){
                l[l_index].value=p[i]+p[j]+p[k];
                l[l_index].a=i;
                l[l_index].b=j;
                l[l_index++].c=k;
            }
    int i;
    for (i=0; i<sizeof(l)/sizeof(l[0])-1; i++)
        if (l[i].value == n) break;
    
    if (i==sizeof(l)/sizeof(l[0])-1){
        printf("impossible");
        return 0;
    }
    
    
    int a=l[i].a, b=l[i].b, c=l[i].c;

    print_combination(a,p);
    print_combination(b,p);
    print_combination(c,p);
    
    
    return 0;
}
void print_combination(int x, int p[]){
    if (x<20)
        printf("triple %d\n",p[x]/3);
    else if (x<40)
        printf("double %d\n",p[x]/2);
    else if (x<60)
        printf("single %d\n",p[x]);
    
    return;
}

