#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	double A,N;
	cin >> A >> N;

	if (4*M_PI*A <= N*N) cout << "Diablo is happy!\n";
	else cout << "Need more materials!\n";

	return 0;
}
