#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int W, P;
	cin >> W >> P;

	vector<int> par;
	par.push_back(0);

	int x;
	while(P--){
		cin >> x;
		par.push_back(x);
	}

	par.push_back(W);
	sort(par.begin(), par.end());


	set<int> s;
	for(int i=1; i<par.size(); i++) for(int j=0; j<i; j++){
		s.insert(par[i]-par[j]);
	}

	for(auto x: s) cout << x << " ";
	cout << endl;

	return 0;
}
