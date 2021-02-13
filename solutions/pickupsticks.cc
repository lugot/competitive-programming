#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<int, int> ii;

vector<int> visited; 
vector<int> ts;
vector<vector<int>> adj;
vector<bool> in_stack;
bool cycle;

void toposort(int u) {
    if (cycle) return;
    visited[u] = 1;

    for (auto &v : adj[u]) {
        if (visited[v] == 0) toposort(v);
        if (visited[v] == 1) {
            cycle = true;
            return;
        }
    }
    ts.push_back(u);
    visited[u] = 2;
    return;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n, m;
    cin >> n >> m;

    adj = vector<vector<int>>(n);
    while (m--) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        
        adj[a].push_back(b);
    }

    visited = vector<int>(n, 0);
    ts.clear();
    cycle = false;

    for (int i=0; i<n && !cycle; i++) {
        if (visited[i] != 0) continue;
        toposort(i);
    }
    if (cycle) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    reverse(ts.begin(), ts.end());
    for (int x: ts) cout << x+1 << endl;

	return 0;
}
