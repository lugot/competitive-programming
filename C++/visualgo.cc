#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<pair<int, int>> vii;

const int INF = 1e9; // INF = 1B, not 2^31-1 to avoid overflow

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int V, E;
    cin >> V >> E;

	vector<vector<ii>> adj(V);

	int u, v, w;
    while(E--){
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
    }
	
	int s, t;
	cin >> s >> t;

	if (s == t){
		cout << 1 << endl;
		return 0;
	}

	priority_queue<ii, vector<ii>, greater<ii>> pq; 
	pq.push({0, s});

	vector<int> dist(V, INF); dist[s] = 0;
	vector<int> parent(V, -1); parent[s] = -1;
	vector<vector<int>> paths;

	while (!pq.empty()){
		auto [d, u] = pq.top(); pq.pop();

		if (d > dist[u]) continue;
		for (auto &[v, w] : adj[u]){
			if (dist[u]+w > dist[v]) continue;

			parent[v] = u;
			dist[v] = dist[u]+w;
			pq.push({dist[v], v});



			if (dist[u]+w == dist[v] and v == t){
				vector<int> lol;
				int act = v;
				while(parent[act] != -1){
					lol.push_back(act);
					act = parent[act];
				}
				lol.push_back(act);

				for(auto stored_path: paths){
					if (stored_path.size() != lol.size()) continue;

					bool found_eq = true;
					for(int i=0; i<lol.size(); i++){
						if (lol[i] != stored_path[i]){
							found_eq = false;
						}
					} 

					if (found_eq){
						goto gnam;
						break;
					}
				}

				paths.push_back(lol);
			}
			if (dist[u]+w < dist[v] and v == t){
				vector<int> path;
				int act = t;
				while(parent[act] != -1){
					path.push_back(act);
					act = parent[act];
				}
				path.push_back(act);

				paths.clear();
				paths.push_back(path);
			}	

gnam:
			cout << "";		
		}
	}

	//for(auto path: paths){
		//for(auto x: path) cout << x << " ";
		//cout << endl;
	//}
	cout << paths.size() << endl;

    return 0;
}
