#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	int found=0;
	
	for(int i=0; i<5; i++){
		cin >> s;
		
		for(int j=0; j<s.length()-2; j++)
			if (s.substr(j,3) == "FBI"){
				printf("%d ",i+1);
				found=1;
				break;
			}
	}
	if (!found) printf("HE GOT AWAY!\n");
	else printf("\n");
	
	
	return 0;
}
