#include <bits/stdc++.h>

using namespace std;
	
int main() {
	int n;
	cin >> n;
	getc(stdin);
	
	map<string,int> m;

	string s;
	while(n--) {
		cin >> s;
		
		if (!s.compare("entry")) {
			cin >> s;
			m[s]+=1;
			
			printf("%s entered", s.c_str());
			if (m[s]>1) {
				printf(" (ANOMALY)");
				m[s]=1;
			}

		} else {
			cin >> s;
			m[s]-=1;
			
			printf("%s exited", s.c_str());
			if (m[s]<0) {
				printf(" (ANOMALY)");
				m[s]=0;
			}
		}

		printf("\n");

	}

	return 0;
}
