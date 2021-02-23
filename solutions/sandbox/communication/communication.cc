#include <bits/stdc++.h>

using namespace std;

int main(){

	int n;
	cin >> n;

	while (n--) {
		int b;
		cin >> b;

		for (int i=0; i<=255; i++) {
			
			if ((0xFF & (i ^ (i << 1))) != b) continue;

			cout << (int)i << " ";
			break;
		}
	}
	cout << endl;

	return 0;
}
