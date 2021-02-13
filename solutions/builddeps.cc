#include <algorithm>
#include <bits/stdc++.h>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<int, int> ii;

/*
 *TOPOSORTING
 */

vector<vector<int>> adj;
vector<int> visited; 
vector<int> ts;

void toposort(int u) {
    visited[u] = 1;
    for (auto &v : adj[u]) if (!visited[v]) toposort(v);
    ts.push_back(u);
}
/*in main:
 *    visited = vector<int>(n, 0);
 *    toposort(s, adj);
 *    reverse(ts.begin(), ts.end());
 */



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    string temp;
    getline(cin, temp);
    int n = stoi(temp);

    unordered_map<string, int> dir;
    unordered_map<int, string> inv;
    int idx = 0;

    visited = vector<int>(n, 0);
    adj = vector<vector<int>>(n);
    ts.clear();

    while (n--) {
        string line;
        getline(cin, line);

        stringstream ss(line);

        vector<string> lsplit;
        string a;
        while (ss >> a) lsplit.push_back(a);

        lsplit[0] = lsplit[0].substr(0, lsplit[0].size()-1);

        for (string s: lsplit) {
            if (dir.count(s) == 0) {
                dir[s] = idx;
                inv[idx++] = s;
            }
        }

        for (int i=1; i<lsplit.size(); i++) adj[dir[lsplit[i]]].push_back(dir[lsplit[0]]);
    }

    string s;
    cin >> s;
    toposort(dir[s]);
    reverse(ts.begin(), ts.end());

    for (int x: ts) cout << inv[x] << endl;

	return 0;
}
