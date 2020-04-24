#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	cin >> N;

	string s;
	while(N--) {
		cin >> s;
	
		if (!s.compare("P=NP")) cout << "skipped" << endl;
		else {
			int i=0;
			while (s[i]!='+') i++;
				printf("%d\n",
					stoi(s.substr(0,i-0+1),nullptr,10) + 
					stoi(s.substr(i+1),nullptr,10));
		}
		

	}
	


	return 0;
}
