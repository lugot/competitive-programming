#include<stdio.h>
#include<string.h>

#define MIN(a,b) (((a)<(b))?(a):(b))

char c[50];

int main(){
	int i,T,C,G,score,min;
	
	scanf("%s",c);
	
	T=C=G=0;
	for (i=0; i<strlen(c); i++)
		switch(c[i]){
			case 'T': T++; break;
			case 'C': C++; break;
			case 'G': G++; break;
		}
		
	score = T*T + C*C + G*G;
	
	min=T;
	min = MIN(min,C);
	min = MIN(min,G);
	score+=min*7;
	
	printf("%d\n",score);
	
	return 0;
}
