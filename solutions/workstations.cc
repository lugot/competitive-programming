#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int main(){

	int n, m;
	cin >> n >> m;

	vector<ii> intervals(n);

	int a, s;
	for (ii& interval: intervals) {
		cin >> a >> s;

		interval.first = a;
		interval.second = a+s;
	}

	sort(intervals.begin(), intervals.end());
	priority_queue<int, vector<int>, greater<int>> q;

	int ans = 0;
	for (int i=0; i<n; i++) {
		auto [s, e] = intervals[i];

		//cout << s << " " << e << " " << q.size() << " " << ans <<  endl;

		while (!q.empty() and s - q.top() > m) q.pop();
		if (q.empty() or (!q.empty() and q.top() > s)) ans++;
		else q.pop();

		q.push(e);
	}

	cout << n-ans << endl;

	return 0;
}
