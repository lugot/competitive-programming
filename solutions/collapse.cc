#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<int, int> ii;

vector<vector<ii>> adj;
vector<int> goods;

vector<bool> topodummy(int s) { 

    int n = adj.size();

    vector<int> deg(n, 0); 
    for (int u=0; u<n; u++) {
        for (auto [v, w]: adj[u]) deg[v] += w;
    }

	priority_queue<ii, vector<ii>> pq; 
    pq.push({deg[s], s});
    
    vector<bool> collapsed(n, false);
    collapsed[s] = true;

    while (!pq.empty()) {
        auto [dummy, v] = pq.top(); pq.pop();

        for (auto [u, w]: adj[v]) {
            if (collapsed[u]) continue;

            deg[u] -= w;
            if (deg[u] < goods[u] && !collapsed[u]) {
                collapsed[u] = true;
                pq.push({deg[u], u});
            }
        }
    }

    return collapsed;
} 


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    int N;
    cin >> N;

    goods = vector<int>(N, 0);
    adj = vector<vector<ii>>(N);

    for (int i=0; i<N; i++) {
        int K;
        cin >> goods[i] >> K;

        int S, V;
        while (K--) {
            cin >> S >> V;
            adj[S-1].push_back({i, V});
        }
    }

    vector<bool> collapsed = topodummy(0);

    int ans = 0;
    for (bool b: collapsed) if (!b) ans++;

    cout << ans << endl;

	return 0;
}
