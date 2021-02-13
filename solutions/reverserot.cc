#include <bits/stdc++.h>

using namespace std;

int main() {
	int N;
	string s,r, alp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";


	while(1) {
		cin >> N;
		if (N==0) break;

		cin >> s;
		for (int i=0; i<s.length(); i++) {
			int index = (alp.find(s.at(i)) + N);
			if (index >= alp.length()) index = index % alp.length();
			else index %= alp.length();
			
			r = alp[index] + r;
		}
		printf("%s\n",r.c_str());
		r = "";
	}

	return 0;
}
