#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while(T--){
		int NG, NM;
		cin >> NG >> NM;

		vector<int> g(NG), m(NM);
		for(auto &x: g) cin >> x;
		for(auto &x: m) cin >> x;

		sort(g.begin(), g.end());
		sort(m.begin(), m.end());

		int i, j;
		i = j = 0;

		while(i<NG and j<NM){
			if (g[i] == m[j]) j++;
			else if (g[i] < m[j]) i++;
			else j++;
		}
		
		if (i == NG) cout << "MechaGodzilla\n";
		else cout << "Godzilla\n";

	}

	return 0;
}
