#include <bits/stdc++.h>
#include <vector>

using namespace std;

typedef pair<int, double> id;
typedef pair<double, int> di;

const int INF = 1e9; // INF = 1B, not 2^31-1 to avoid overflow

struct point{
    int x, y;
};
double dist(point& a, point& b){
	return hypot(a.x - b.x, a.y - b.y);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n;
    cin >> n;

    n+=2;
	vector<point> points;
    int x, y;
    while(n--){
        cin >> x >> y;
        points.push_back({x, y});
    }
    n = points.size();

    vector<vector<double>> adj(n, vector<double>(n, 0.0));
    for(int i=0; i<n; i++){ 
        for(int j=0; j<n; j++){
            if (j == i) continue;
            adj[i][j] = pow(dist(points[i], points[j]), 2);
        }
    }

    int s = n-2;
    int t = n-1;

    priority_queue<di, vector<di>, greater<di>> pq; 
    pq.push({0, s});

    vector<double> dist(n, INF); dist[s] = 0;
    vector<int> parent(n, -1); parent[s] = -1;

    while (!pq.empty()){
        auto [d, u] = pq.top(); pq.pop();

        if (d > dist[u]) continue;
        //for (auto &[v, w] : adj[u]){
        for(int i=0; i<n; i++){
            int v = i;
            int w = adj[u][v];
            if (dist[u]+w >= dist[v]) continue;
            dist[v] = dist[u]+w;
            parent[v] = u;
            pq.push({dist[v], v});
        }
    }

    vector<int> path;
    int act = t;
    while(parent[act] != -1){
        path.push_back(act);
        //cout << act << " ";
        act = parent[act];
    }
    path.push_back(s);

    if (path.size() == 2) cout << "-" << endl;
    else for(int i=path.size()-2; i>0; i--) cout << path[i] << endl;
	return 0;
}
