#include <bits/stdc++.h>

using namespace std;

int n;
string a, b;

int pos(string a) {

	long long ans = 0;
	for (int i=0; i<n; i++) {
		if (a[n-i-1] == '1') ans = (1 << i+1) -1 - ans;
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> a >> b;

	cout << pos(b)-pos(a)-1 << endl;

	return 0;
}
