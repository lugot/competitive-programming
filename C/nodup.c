#include<stdio.h>
#include<string.h>

char phrase[160];
char *words[160];

int main(){
	int words_index,phrase_index,length,i,j;
		
	scanf("%[^\n]",phrase);
	
	words_index=0;
	words[words_index++]=phrase;
	length=strlen(phrase);
	for (phrase_index=1; phrase_index<length; phrase_index++){
		
		if (phrase[phrase_index]==' '){
			phrase[phrase_index]=0;
			words[words_index++]= phrase + phrase_index +1;
		}
	}
	
	for(i=0; i<words_index; i++)
		for(j=0; j<words_index; j++){
			if (i==j) continue;
			if (!strcmp(words[j],words[i])){
				printf("no\n");
				return 1;
			}
		}
	
	printf("yes\n");
	return 0;
}
