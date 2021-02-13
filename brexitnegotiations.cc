#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;


void topo(int u ){
	dfs_num[u] = VISITED;
	for (int j = 0; j < (int)AdjList[u].size(); j++) {
	ii v = AdjList[u][j];
	if (dfs_num[v.first] == UNVISITED)
	dfs2(v.first);
	}
	ts.push_back(u);
}
 

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> e;
	vector<vector<int>> adj(n);
	vector<int> starts(n, 0);

	for(int i=0; i<n; i++){
		int d;
		cin >> e[i] >> d;

		if (d==0) starts[i] = 1;
		
		for(int j=0; j<d; j++){
			int b;
			cin >> b;

			adj[b-1].push_back(i);
		}
	}

	vector<int> ts, visited(n, 0);
	priority_queue<ii, vector<ii>> topo;

	for(int i=0; i<n; i++) if (starts[i]) topo.push({-e[i], i});

	while(!topo.empty()){
		auto [d, act] = topo.top(); topo.pop();
		d = -d;

	}





	return 0;
}
