#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;
	getc(stdin);

	int map[27] = {
		2,
		22,
		222,
		3,
		33,
		333,
		4,
		44,
		444,
		5,
		55,
		555,
		6,
		66,
		666,
		7,
		77,
		777,
		7777,
		8,
		88,
		888,
		9,
		99,
		999,
		9999,
		0};

	string s;
	int prev;
	for(int i=0; i<N; i++){
			
		getline(cin,s);
		for(int i=0; i<s.length(); i++) if (s[i]==' ') s[i]=(char)'z'+1;
		prev = map[s[0] - 'a'] % 10;


		printf("Case #%d: %d", i+1, map[s[0] - 'a']);
		for(int i=1; i<s.length(); i++){
			
			int to_print = map[s[i] - 'a'];
			if ( to_print%10 == prev) {
				printf(" ");
			}
			printf("%d",to_print);
			prev = to_print%10;
		}
		printf("\n");

	}

	return 0;
}
