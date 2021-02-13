#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	getc(stdin);
	
	int alph[26];

	string s;
	while(N--) {
		getline(cin,s);
		bzero(alph,26*sizeof(int));

		for(int i=0; i<s.length(); i++) {
			if (97 <= s[i] && s[i] <=122) s[i]-=32;
			if (65 <= s[i] && s[i] <= 90) alph[s[i]-65]=1;
		}

		int pangram=1;
		for(int i=0; i<26; i++) if (alph[i]==0) pangram=0;

		if (pangram) printf("pangram\n");
		else {
			printf("missing ");
			for(int i=0; i<26; i++) if (alph[i]==0) printf("%c", (i+97));
			printf("\n");
		}
	}
	
	return 0;
}
