#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	string n;
	cin >> T;

	while (T--) {
		int a=1;
		int c=0;
		
		cin >> n;
		
		for (int i=n.length()-1 ; i>=0; i--){
			int dig = n.at(i) - '0';

			if (a==0) {
				dig*=2;
				if (dig>=10) dig = dig%10 + dig/10;
				a=1;
			} else {
				a=0;
			}

			c += dig;
		}
		if (c%10 == 0) cout << "PASS\n";
		else cout << "FAIL\n";
	}
		

	return 0;
}
