#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

const int INF = 1e9; // INF = 1B, not 2^31-1 to avoid overflow


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int P, T;
	cin >> P >> T;

	vector<vector<ii>> adj(P);
	while(T--){
		int v, w, d;
		cin >> v >> w >> d;

		adj[v].push_back({w, d});
		adj[w].push_back({v, d});
	}

	priority_queue<ii, vector<ii>, greater<ii>> pq; 
	pq.push({0, 0});

	vector<int> dist(adj.size(), INF); dist[0] = 0;
	vector<int> parent(adj.size(), -1); parent[0] = -1;

	while (!pq.empty()){
		auto [d, u] = pq.top(); pq.pop();

		if (d > dist[u]) continue;
		for (auto &[v, w] : adj[u]){
			if (dist[u]+w > dist[v]) continue;
			dist[v] = dist[u]+w;
			parent[v] = u;
			pq.push({dist[v], v});
		}
	}

	vector<int> path;
	int act = P-1;
	while(parent[act] != -1){
		path.push_back(act);
		//cout << act << " ";
		act = parent[act];
	}
	path.push_back(0);

	int rawdist = 0;
	for(int i=0; i<path.size()-1; i++){

		int mult = 0;
		int mindist = INF;
		for(auto [v, d]: adj[path[i]]){
			if (v == path[i+1]){
				if (d < mindist){
					mindist = d;
					mult = 0;
				}
				if (d == mindist) mult++;
			}
		}

		rawdist += mindist*= mult;

	}

	int overtotal = rawdist;


	//for(int i=path.size()-1; i>=0; i--) cout << path[i] << " ";
	//cout << endl << dist[P-1] << " " << rawdist << endl;

	for(int i=0; i<path.size()-1; i++){
		for(int k=0; k<adj[path[i]].size(); k++){
			if (adj[path[i]][k].first == path[i+1]){
				adj[path[i]][k].second = INF;
			}
		}
	}
	for(int i=path.size()-1; i>0; i--){
		for(int k=0; k<adj[path[i]].size(); k++){
			if (adj[path[i]][k].first == path[i-1]){
				adj[path[i]][k].second = INF;
			}
		}
	}


	priority_queue<ii, vector<ii>, greater<ii>> pq1; 
	pq1.push({0, 0});


	vector<int> dist1(adj.size(), INF); dist1[0] = 0;
	vector<int> parent1(adj.size(), -1); parent1[0] = -1;

	while (!pq1.empty()){
		auto [d, u] = pq1.top(); pq1.pop();

		if (d > dist1[u]) continue;
		for (auto &[v, w] : adj[u]){
			if (dist1[u]+w > dist1[v]) continue;
			dist1[v] = dist1[u]+w;
			parent1[v] = u;
			pq1.push({dist1[v], v});
		}
	}

	vector<int> path1;
	int act1 = P-1;
	while(parent1[act1] != -1){
		path1.push_back(act1);
		//cout << act << " ";
		act1 = parent1[act1];
	}
	path1.push_back(0);

	int rawdist1 = 0;
	for(int i=0; i<path1.size()-1; i++){

		int mult = 0;
		int mindist = INF;
		for(auto [v, d]: adj[path1[i]]){
			if (v == path1[i+1]){
				if (d < mindist){
					mindist = d;
					mult = 0;
				}
				if (d == mindist) mult++;
			}
		}

		rawdist1 += mindist*= mult;

	}

	//for(int i=path1.size()-1; i>=0; i--) cout << path1[i] << " ";
	//cout << endl << dist1[P-1] << " " << rawdist1 << endl;
	//
	cout << 2*rawdist1 + 2*overtotal << endl;


	return 0;
}
