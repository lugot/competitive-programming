#include <bits/stdc++.h>

using namespace std;
const double INF = DBL_MAX/2.0;
typedef pair<long double, int> di;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	while(cin >> n >> m){
		if (n==0) break;

		vector<vector<pair<int, double>>> adj(n);

		int x, y;
		double f;
		while(m--){
			cin >> x >> y >> f;

			adj[x].push_back({y, f});
			adj[y].push_back({x, f});
		}

		vector<double> dist(n, 0);
		dist[0] = 1;
		vector<bool> visited(n, false);
		visited[0] = true;

		priority_queue<di, vector<di>> pq;
		pq.push({1.0, 0});

		// lol non funzionera mai
		while(!pq.empty()){
			double d = pq.top().first;
			int u = pq.top().second;
			pq.pop();

			//if (visited[u]) contine;
			//visited[u] = true;
			if (d > dist[u]) continue;

			for(auto [v, f]: adj[u]){
				if (dist[u]*f > dist[v]){
					 dist[v] = dist[u]*f;
					 pq.push({dist[v], v});
				}
			}
		}

		cout << fixed;
		cout.precision(4);
		cout << dist[n-1] << endl;
	}

	return 0;
}
