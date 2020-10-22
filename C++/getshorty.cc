#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 0.0;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	while(cin >> n >> m){
		if (n == 0) break;

		vector<vector<pair<int, float>>> adj(n);

		while(m--){
			int x, y;
			float f;
			cin >> x >> y >> f;

			adj[x].push_back({y, f});
			adj[y].push_back({x, f});
		}

		vector<float> distance(n);
		for(auto &x: distance) x = 1000000.0;
		distance[0] = 0.0;
		vector<int> parent(n, 0);

		priority_queue<pair<float, int>, vector<pair<float, int>>> q;
		q.push({0.0, 0});

		while(!q.empty()){
			auto x = q.top(); q.pop();
			float d = -x.first;
			int u = x.second;
			cout << "u: " <<  u << d << endl;
			if (d > distance[u]) continue;

			cout << "here: " << endl;
			for(auto y: adj[u]){
				int v = y.first;
				float w = y.second; 
				cout << "v: " << v << ",w: " << w << endl;

				if (distance[u] + w < distance[v]){
				cout << "v: " << v << ",w: " << w << endl;
					distance[v] = distance[u] + w;
					parent[v] = u;
					q.push({-distance[v], v});
				}
			}
		}


		for(auto x: parent) cout << x << " ";
		int act = n-1;
		while(act != 0){
			cout << parent[act] << " ";
			act = parent[act];
		}
		cout << endl;
	}

	return 0;
}

