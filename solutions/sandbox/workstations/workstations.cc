#include <bits/stdc++.h>

using namespace std;

int main(){

	int n, m;
	cin >> n >> m;

	vector<int> starts(n), ends(n);

	int a, s;
	for (int i=0; i<n; i++) {
		cin >> a >> s;

		starts[i] = a;
		ends[i] = a+s;
	}

	sort(starts.begin(), starts.end());
	sort(ends.begin(), ends.end());
	vector<int> taken(n, 0);

	int ans = n;
	for (int i=0; i<n; i++) {
		int idx = lower_bound(ends.begin(), ends.end(), starts[i]) - ends.begin();
		if (starts[idx] != ends[i]) idx--;
		idx = max(0, idx);

		while (taken[idx]) idx--;
		int finish_searched = ends[idx];

		int diff = starts[i] - finish_searched;
		if (diff >= 0 and diff <= m) {
			ans--;
			taken[idx] = 1;
		}

		//cout << starts[i] << " " << finish_searched << " " << ans << endl;
	}

	cout << n - ans << endl;



	return 0;
}
