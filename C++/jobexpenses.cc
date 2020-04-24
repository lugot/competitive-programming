#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;

	int ans=0, x;
	while(cin >> x) if (x<0) ans+=x;

	cout << ans*-1 << endl;


	return 0;
}
