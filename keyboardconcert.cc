#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
#include <vector>

#define INF 1e9

using namespace std;

int n, m;
int k, l;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m;
    vector<vector<int>> sw(m, vector<int>(n, 0));

    vector<set<int>> instrument(n);
    for (int i=0; i<n; i++) {
        cin >> k;

        while (k--) {
            cin >> l;
            instrument[i].insert(l);
        }
    }

    vector<int> notes(m);
    for (int& note: notes) cin >> note;

    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            
            if (instrument[j].count(notes[i]) == 0) {
                sw[i][j] = INF;
            }
            else if (i == 0) {
                sw[i][j] = 0;
            }
            else {
                sw[i][j] = *min_element(sw[i-1].begin(), sw[i-1].end());

                if (sw[i][j] != sw[i-1][j]) sw[i][j]++;
            }
        }
    }

    //for (auto x: sw) {
        //for (auto y: x) cout << (y == INF ? "X" : to_string(y)) << " ";
        //cout << endl;
    //}
    cout << *min_element(sw[m-1].begin(), sw[m-1].end()) << endl;

	return 0;
}
