#include<bits/stdc++.h>
#include <queue>
using namespace std;

typedef double wtype; // change weighttype

typedef pair<int, wtype> iw;
typedef pair<wtype, int> wi;
typedef vector<iw> viw;
typedef vector<int> vi;
typedef vector<viw> adjlist;

typedef pair<int, int> ii;

int n, m, k;
adjlist alist;
vi visited;
vi dist;
vi color;

vi status;
int INF = 1e6;

// BFS
void bfs(int x) {
    visited[x] = 1;
    dist[x] = 0;

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({dist[x], x});

    while (!pq.empty()) {
        auto [distance, u] = pq.top(); pq.pop();

        for (auto [v, w]: alist[u]) {
            color[v] = color[u];
            if (status[u] != 0) color[v] = 1;

            int newdist;
            if (color[u] != color[v] and !color[u]) newdist = 1;
            else newdist = dist[u]+1;

            if (newdist >= dist[v]) continue;

            visited[v] = 1;
            dist[v] = newdist;

            pq.push({dist[v], v});
        }
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m >> k;

    status = vi(n, 0);

    for (int i=0; i<m; i++) {
        int o;
        cin >> o;
        o--;

        status[o] = 1;
    }
    for (int i=0; i<k; i++) {
        int c;
        cin >> c;
        c--;

        status[c] = 2;
    }

    alist = adjlist(n);
    for (viw& neigh: alist) {
        int a;
        cin >> a;

        neigh = viw(a);
        for (auto& [u, w]: neigh) cin >> u;
        for (auto& [u, w]: neigh) u--;
    }

    visited = vi(n, 0);
    dist = vi(n, INF);
    dist[0] = 0;
    color = vi(n, 0);
    bfs(0);

    int ans1, ans2;
    ans1 = ans2 = INF;
    for (int i=0; i<n; i++) {
        if (status[i] != 1) continue;

        ans1 = min(ans1, dist[i]);
    }
    for (int i=0; i<n; i++) {
        if (status[i] != 2) continue;

        ans2 = min(ans2, dist[i]);
    }

    if (ans1 == INF or ans2 == INF) cout << "impossible" << endl;
    else                            cout << ans1+ans2 << endl;

    return 0;
}
