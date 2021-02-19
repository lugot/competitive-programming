#include <bits/stdc++.h>

using namespace std;

typedef int wtype; 

typedef pair<int, wtype> iw;
typedef pair<wtype, int> wi;
typedef vector<iw> viw;
typedef vector<int> vi;
typedef vector<viw> adjlist;

int n, m;  
adjlist alist;
vi visited;
vi parent;
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
	return 0;
}
