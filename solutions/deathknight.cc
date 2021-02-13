#include <bits/stdc++.h>

using namespace std;

int main() {
	int n,count=0;
	cin >> n;
	
	string s;
	while (n--) {
		cin >> s;

		for (int i=1; i<s.length(); i++) 
			if (s[i-1] == 'C' && s[i] == 'D') {
				count--;
				break;
			}
		count++;
	}

	cout << count << endl;

	return 0;
}
