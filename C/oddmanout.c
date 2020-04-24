#include<stdio.h>

int main(){
	int N,C,G,i,guest_index,search_index;
	
	scanf("%d\n",&N);
	
	for(i=0; i<N; i++){
		scanf("%d\n",&G);
		unsigned int guest[G];
		guest_index=0;
		
		for(guest_index=0; guest_index<G;){
			scanf("%d ",&guest[guest_index++]);
			
			for (search_index=0; search_index<guest_index-1; search_index++)
				if (guest[search_index]==guest[guest_index-1]){
					guest[search_index]=0;
					guest[guest_index-1]=0;
				}
		}
		search_index=0;
		while(guest[search_index]==0) search_index++;
		
		printf("Case #%d: %d\n",i+1,guest[search_index]);
		
		
	}
	
	
	return 0;
}
