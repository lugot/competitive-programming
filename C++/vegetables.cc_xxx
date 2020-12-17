#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	double T;
	int N;
	cin >> T >> N;

	vector<int> veg(N);
	for(auto &x: veg) cin >> x;
	sort(veg.begin(), veg.end());

	int b = veg[0]/(T+1);
	int a = veg[0] - b;

	int ans = 1;
	for(int i=1; i<veg.size(); i++){
		while(!(veg[i] <= a+b and veg[i] >= a)){
			ans++;
			veg[i] -= b;
			cout << veg[i] << endl;
		}
		ans++;
	}

	cout << ans << endl;
	

	return 0;
}
