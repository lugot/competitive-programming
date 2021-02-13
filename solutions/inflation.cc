#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	vector<int> can(n);
	for(auto &x: can) cin >> x;

	sort(can.begin(), can.end());
	
	double f = 1.0;
	for(int i=1; i<=n; i++){
		if (can[i-1] > i){
			cout << "impossible\n";
			return 0;
		}

		f = min(f, (double)can[i-1]/i);
	}

	cout << f << endl;


	return 0;
}
