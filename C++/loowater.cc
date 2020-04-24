#include<stdio.h>
#include<stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));

int main(){
    
    
 
    
    int n,m;
    scanf("%d %d",&n,&m);

    do
    {        
        int h[n];
        int k[m];
        for (int i=0; i<n; i++)
            scanf("%d",&h[i]);
        for (int i=0; i<m; i++)
            scanf("%d",&k[i]);
        
        /*
        for (int i=0; i<n; i++)
            printf("%d\n",h[i]);
        for (int i=0; i<m; i++)
            printf("%d\n",k[i]);
        */
        
        qsort(h, n, sizeof(int), cmpfunc);
        qsort(k, m, sizeof(int), cmpfunc);
            
        int cost=0;
        int flag=0;
        for (int i=0; i<n; i++){
            
            int j;
            for (j=0; j<m; j++)
                if (k[j]>=h[i]) break;
            
            if (j==m){ //non ci sono soldati abbastanza alti
                flag=1;
                break;
            }
            
            cost+=k[j];
            k[j]=0;
            h[i]=0;
        }
        
        
        if (!flag)
            printf("%d\n",cost);
        else
            printf("Loowater is doomed!\n");
        
        scanf("%d %d",&n,&m);
    }while(n!=0 && m!=0);
    
    return 0;
}
