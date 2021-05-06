#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll T, L, R;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> L >> R;

		ll layer = L+R+1;
		cout << 1 + layer*(layer-1)/2 + R << endl;
	}

	return 0;
}
