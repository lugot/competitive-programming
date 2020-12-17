#include <bits/stdc++.h>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

const int INF = 1e9; // INF = 1B, not 2^31-1 to avoid overflow

struct node{
    int v, d, t0, P;
	bool operator<(node n){
		return d > n.d;
	}
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q, s;
    while(true){
        cin >> n >> m >> q >> s;
        if (n == 0) break;

        vector<vector<node>> adj(n);

        int u, v, t0, P, d;
        while(m--){
            cin >> u >> v >> t0 >> P >> d;
            adj[u].push_back({v, t0, P, d});
        }

        priority_queue<ii, vector<ii>, greater<ii>> pq; 
        pq.push({0, s});

        vector<double> dist(adj.size(), INF); dist[s] = 0;

        while (!pq.empty()){
            auto [du, u] = pq.top(); pq.pop();

            if (du > dist[u]) continue;
            for (auto &[v, t0, P, d] : adj[u]){

                int new_time;
                if (P == 0){
                    if (du > t0) continue;
                    else new_time = t0;
                }
                else if (t0 == 0) new_time = ((int)du/P)*P + P;
                else{
                    if (du <= t0) new_time = t0;
                    else 
                    new_time = ((int)du/t0)*t0 + P;
                }

                if (new_time + d >= dist[v]) continue;
                dist[v] = new_time + d;
                pq.push({dist[v], v});
            }
        }



        int t;
        while(q--){
            cin >> t;

            if (dist[t] == INF) cout << "Impossible" << endl;
            else cout << dist[t] << endl;
        }
        cout << endl;
    }
    return 0;
}
