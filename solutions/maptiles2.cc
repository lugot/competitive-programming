#include <bits/stdc++.h>

using namespace std;

int main(){

	string s;
	cin >> s;

	int zoom_level = s.length();

	int x, y;
	x = y = 0;

	int i = 0;
	for (int j=s.length()-1; j>=0; j--) {
		int cipher = s[j] - '0';

		if (cipher == 3) {
			x += (int)pow(2, i);
			y += (int)pow(2, i);
		}
		else if (cipher == 2) {
			y += (int)pow(2, i);
		}
		else if (cipher == 1) {
			x += (int)pow(2, i);
		}

		i++;
	}

	cout << zoom_level << " " << x << " " << y << endl;

	return 0;
}
