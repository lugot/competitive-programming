#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	scanf("%d\n",&N);

	string s;
	for (int i=0; i<N; i++) {
		getline(cin,s);
		
		if (!s.substr(0,10).compare("Simon says"))
			printf("%s\n", s.substr(11).c_str());

	}

	return 0;
}
