#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int S, C, K;
	cin >> S >> C >> K;

	vector<int> socks(S);
	for(auto &x: socks) cin >> x;

	set<int> s(socks.begin(), socks.end());
	socks.assign(s.begin(), s.end());
	sort(socks.begin(), socks.end());

	int ans = 1;
	int i = 0, act = socks[0];
	int c = 0;
	while(i<socks.size()-1){
		if (socks[i+1] - act <= K) i++;
		else{
			ans++;
			i++;
			act = socks[i];
		}
	}

	cout << ans << endl;

	return 0;
}
