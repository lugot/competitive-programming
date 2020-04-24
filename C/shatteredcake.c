#include<stdio.h>

int main(){
	int W,N,area,wi,li;
	scanf("%d\n",&W);
	scanf("%d\n",&N);
	
	area=0;
	for (int i=0; i<N; i++){
		scanf("%d %d",&wi,&li);
		area+=wi*li;
	}
	
	printf("%d\n",area/W);
	return 0;
}

/*
4
7
2 3
1 4
1 2
1 2
2 2
2 2
2 1
*/
