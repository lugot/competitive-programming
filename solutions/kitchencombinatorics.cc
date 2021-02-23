#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int r, s, m, d, n;
	cin >> r >> s >> m >> d >> n;

	vector<int> m_ing(r);
	for (int& b: m_ing) cin >> b;

	vector<vector<int>> dishes(s+m+d+1);
	for (int i=1; i<=s+m+d; i++) {
		int k;
		cin >> k;

		dishes[i] = vector<int>(k);
		for (int& i: dishes[i]) cin >> i;
		for (int& i: dishes[i]) i--;
	}
	map<pair<int, int>, int> incomp;
	for (int i=0; i<n; i++) {
		int a, b;
		cin >> a >> b;

		incomp[{a, b}] = 1;
		incomp[{b, a}] = 1;
	}


	__int128 ans = 0;
	__int128 upper_bound = 1e18;
	for (int i=1; i<=s; i++) {
		for (int j=s+1; j<=s+m; j++) {
			if (incomp[{i, j}] == 1) continue;

			for (int k=s+m+1; k<=s+m+d; k++) {

				if (incomp[{i, k}] == 1) continue;
				if (incomp[{j, k}] == 1) continue;

				set<int> s;
				for (int ing: dishes[i]) s.insert(ing);
				for (int ing: dishes[j]) s.insert(ing);
				for (int ing: dishes[k]) s.insert(ing);

				__int128 mult = 1;
				for (int ing: s) {
					mult *= m_ing[ing];
					//cout << ing << " " << m_ing[ing] << " " << mult << endl;;
					if (mult > upper_bound) {
						cout << "too many" << endl;
						return 0;
					}
				}

				ans += mult;
				if (mult > upper_bound or ans > upper_bound) {
					cout << "too many" << endl;
					return 0;
				}
			}
		}
	}

	cout << (long long) ans << endl;

	return 0;
}
