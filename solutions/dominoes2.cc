#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, m, l;
        cin >> n >> m >> l;

        vector<vector<int>> next(n);
        int x, y;
        while (m--) {
            cin >> x >> y;
            x--, y--;
            next[x].push_back(y);
        }

        vector<bool> knoked(n, false);
        int z;
        while (l--) {
            cin >> z;
            z--;

            queue<int> q;
            q.push(z);
            knoked[z] = true;
            while (!q.empty()) {
                z = q.front(); q.pop();

                for (int d: next[z]) {
                    if (knoked[d]) continue;
                    knoked[d] = true;
                    q.push(d);
                }
            }
        }

        int ans = 0;
        for (auto x: knoked) if (x) ans++;
        
        cout << ans << endl;
    }

	return 0;
}
