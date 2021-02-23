#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int r, s, m, d, n;
	cin >> r >> s >> m >> d >> n;

	vector<int> m_ing(r);
	for (int& b: m_ing) cin >> b;

	vector<vector<int>> starters(s);
	for (vector<int>& s: starters) {
		int k;
		cin >> k;

		s = vector<int>(k);
		for (int& i: s) cin >> i;
		for (int& i: s) i--;
	}
	vector<vector<int>> mains(m);
	for (vector<int>& m: mains) {
		int k;
		cin >> k;

		m = vector<int>(k);
		for (int& i: m) cin >> i;
		for (int& i: m) i--;
	}
	vector<vector<int>> desserts(d);
	for (vector<int>& d: desserts) {
		int k;
		cin >> k;

		d = vector<int>(k);
		for (int& i: d) cin >> i;
		for (int& i: d) i--;
	}
	map<pair<int, int>, int> incomp;
	for (int i=0; i<n; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;

		incomp[{a, b}] = 1;
		incomp[{b, a}] = 1;
	}


	long long ans = 0;
	for (int i=0; i<s; i++) {
		for (int j=0; j<m; j++) {
			if (incomp[{i, j+m}] == 1) continue;

			for (int k=0; k<d; k++) {
				if (incomp[{i, k+d+m}] == 1) continue;
				if (incomp[{j+m, k+d+m}] == 1) continue;

				vector<int> merged;
				for (int ing: starters[i]) merged.push_back(ing);
				for (int ing: mains[j])    merged.push_back(ing);
				for (int ing: desserts[k]) merged.push_back(ing);

				set<int> s(merged.begin(), merged.end());
				merged.assign(s.begin(), s.end());

				long long mult = 1;
				for (int ing: merged) mult *= m_ing[ing];

				ans += mult;
				if (ans > 1e18) {
					cout << "too many" << endl;
					return 0;
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}
