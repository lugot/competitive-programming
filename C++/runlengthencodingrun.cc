#include <bits/stdc++.h>

using namespace std;

int main() {
	char mode, buff[0];
	int rep=1;
	string s,r;
	cin >> mode >> s;
	

	if (mode=='E') {
		char c=s[0];

		for(int i=1; i<s.length(); i++) {

			if (s[i]!=c) {	
				buff[0]=c;
				r.append(buff);
				buff[0] = '0' + rep;
				r.append(buff);
				rep=1;
				c = s[i];
			} else rep++;

		}
		buff[0]=c;
		r.append(buff);
		buff[0] = '0' + rep;
		r.append(buff);
		printf("%s\n", r.c_str());
		
		

	} else {
		
		for (int i=0; i<s.length(); i+=2) {
			rep = s[i+1] - '0';
			
			for (int j=0; j<rep; j++) printf("%c",s[i]);
		}
	}
		
	return 0;
}
