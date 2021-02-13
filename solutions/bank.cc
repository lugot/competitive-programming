#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N,T;
	cin >> N >> T;
	
	vector<int> sol(T+1);

	int c,t;
	while(N--){
		cin >> c >> t;

		for(int i=t; i>=0; i--) if (c > sol[i]) swap(c, sol[i]);
	}

	int ans = 0;
	for(auto c: sol) ans+=c;

	cout << ans << endl;

	return 0;
}
