#include <bits/stdc++.h>

using namespace std;

int main() {
	string n1,n2;
	cin >> n1 >> n2;
	
	if (n1.length() > n2.length()) n2 = string( n1.length() - n2.length(), '0') + n2;
	else if (n2.length() > n1.length()) n1 = string( n2.length() - n1.length(), '0') + n1;

	int r1,r2, i1, i2;
	r1 = r2 = i1 = i2 = 0;
	for (int i=n1.length()-1; i>=0; i--) {
		if (n1[i] > n2[i]) r1 += (int) (n1[i] - '0')* pow(10, i1++);
		else if (n1[i] < n2[i]) r2 += (int) (n2[i] - '0')* pow(10, i2++);
		else {
			r1 += (int) (n1[i] - '0')* pow(10, i1++);
			r2 += (int) (n2[i] - '0')* pow(10, i2++);
		}
	}
	
	if (i1!=0) cout << r1 << endl;
	else cout << "YODA" << endl;

	if (i2!=0) cout << r2 << endl;
	else cout << "YODA" << endl;

	return 0;
}
