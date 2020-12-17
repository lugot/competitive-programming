#include <bits/stdc++.h>

using namespace std;

typedef pair<int, double> id;
typedef pair<double, int> di;

const int INF = 1e9; // INF = 1B, not 2^31-1 to avoid overflow

struct tri{
	int x, y, f;
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	vector<tri> nodes;
	int f, x, y;
	while(N--){
		cin >> f >> x >> y;
		nodes.push_back({x, y, f});
	}

	N = nodes.size();
	vector<vector<id>> adj(N+1);
	int n1, n2;
	string s;


	while(M--){
		cin >> n1 >> n2 >> s;
		
		if (s == "walking"){
			double eudist = sqrt(pow(nodes[n1].x - nodes[n2].x, 2) + 
								 pow(nodes[n1].y - nodes[n2].y, 2));

			adj[n1].push_back({n2, eudist});
			adj[n2].push_back({n1, eudist});
		}
		if (s == "stairs"){
			double eudist = sqrt(pow(nodes[n1].x - nodes[n2].x, 2) + 
								 pow(nodes[n1].y - nodes[n2].y, 2) + 
								 pow(5*abs(nodes[n1].f - nodes[n2].f), 2));
			//double eudist = sqrt(pow(nodes[n1].x - nodes[n2].x, 2) + 
								 //pow(nodes[n1].y - nodes[n2].y, 2)) +
								 //5*abs(nodes[n1].f - nodes[n2].f);

			adj[n1].push_back({n2, eudist});
			adj[n2].push_back({n1, eudist});
		}
		if (s == "lift"){
			adj[n1].push_back({n2, 1});
			adj[n2].push_back({n1, 1});
		}
		if (s == "escalator"){
			double eudist = sqrt(pow(nodes[n1].x - nodes[n2].x, 2) + 
								 pow(nodes[n1].y - nodes[n2].y, 2) + 
								 pow(5*abs(nodes[n1].f - nodes[n2].f), 2));
			adj[n1].push_back({n2, 1});
			adj[n2].push_back({n1, 3*eudist});
		}
	}


	int Q;
	cin >> Q;

	while(Q--){
		int a,b;
		cin >> a >> b;

		priority_queue<di, vector<di>, greater<di>> pq; 
		pq.push({0, a});

		vector<double> dist(nodes.size(), INF); dist[a] = 0;
		vector<int> parent(nodes.size(), -1); parent[a] = -1;

		while (!pq.empty()){
			auto [d, u] = pq.top(); pq.pop();

			if (d > dist[u]) continue;
			for (auto &[v, w] : adj[u]){
				if (dist[u]+w >= dist[v]) continue;
				dist[v] = dist[u]+w;
				parent[v] = u;
				pq.push({dist[v], v});
			}
		}

		vector<int> path;
		int act = b;
		while(parent[act] != -1){
			path.push_back(act);
			//cout << act << " ";
			act = parent[act];
		}
		path.push_back(a);

		for(int i=path.size()-1; i>=0; i--) cout << path[i] << " ";
		cout << endl;
	}

	return 0;
}
