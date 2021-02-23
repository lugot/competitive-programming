#include<bits/stdc++.h>
using namespace std;

typedef double wtype; // change weighttype

typedef pair<int, wtype> iw;
typedef pair<wtype, int> wi;
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

void dijkstra(int x) {

    dist = vi(n, INF);
    parent = vi(n, -1);

    priority_queue<wi, vector<wi>, greater<wi>> pq;
    pq.push({0, x});
    dist[x] = 0;
    parent[x] = x;

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, w]: alist[u]) {


            if (dist[u] + w >= dist[v]) continue;

            dist[v] = dist[u] + w;
            parent[v] = u;
            pq.push({dist[v], v});
        }
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m;

    alist = adjlist(n);
    while (m--) {
        int a, b, c;

        cin >> a >> b >> c;
        a--; b--;

        if (c == 1) c = 10000;
        if (c == 0) c = 1;

        alist[a].push_back({b, c});
        alist[b].push_back({a, c});
    }

    dijkstra(0);

    //int ans = dist[n-1] / 10000;
    cout << dist[n-1] / 10000 << endl;


    return 0;
}
