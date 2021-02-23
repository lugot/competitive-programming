#include<bits/stdc++.h>
using namespace std;

typedef double wtype; // change weighttype

typedef pair<int, wtype> iw;
typedef pair<wtype, int> wi;
typedef pair<int, int> ii;
typedef vector<iw> viw;
typedef vector<int> vi;
typedef vector<viw> adjlist;

int n, m;
adjlist alist;
vi visited;
vi parent;
vi restack;
vi dist;

int INF = 1e9;

// BFS
int bfs(int x) {
    int ans = INF;
    visited[x] = 1;
    dist[x] = 0;

    queue<ii> q;
    q.push({x, -1});

    while (!q.empty()) {
        auto [u, parent] = q.front(); q.pop();

        for (auto [v, w]: alist[u]) {
            if (visited[v] and v != parent) {
                ans = min(ans, dist[u] + dist[v] + 1);
                continue;
            }
            if (visited[v]) continue;

            visited[v] = 1;
            dist[v] = dist[u] + 1;

            q.push({v, u});
        }
    }

    return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m;

    alist = adjlist(n);
    while (m--) {
        int u, v;
        cin >> u >> v;

        alist[u].push_back({v, 1});
        alist[v].push_back({u, 1});
    }

    int ans = INF;
    for (int i=0; i<n; i++) {
        dist = vi(n, INF);
        visited = vi(n, 0);

        ans = min(ans, bfs(i));
    }

    if (ans == INF) cout << "impossible" << endl;
    else            cout << ans << endl;


    return 0;
}
