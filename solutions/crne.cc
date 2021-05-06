#include <bits/stdc++.h>

using namespace std;

long long N;

long long ans(long long N) {
	return 2 + N-1 + (N-1)/2*((N-1)/2+1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	if (N%2 != 0) cout << ans(N) << endl;
	else 		  cout << ans(N+1) - (N/2+1) << endl;

	return 0;
}
