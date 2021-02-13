#include <bits/stdc++.h>
#include <vector>

#define INF 1e9

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    int n, m, q;
    while (cin >> n >> m >> q) {
        if (n == 0) break;

        vector<vector<int>> adj(n, vector<int>(n, INF));
        for (int i=0; i<n; i++) adj[i][i] = 0;

        int u, v, w;
        while (m--) {
            cin >> u >> v >> w;
            adj[u][v] = w < adj[u][v] ? w : adj[u][v];
        }

        vector<vector<int>> p(n, vector<int>(n, INF));
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) p[i][j] = i;
 
        for (int k=0; k<n; k++) {
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    if (adj[i][j] > adj[i][k] + adj[k][j] && adj[i][k] < INF && adj[k][j] < INF)
                        adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                for (int k=0; adj[i][j] != -INF && k<n; k++)
                    if (adj[k][k] < 0 && adj[i][k] != INF && adj[k][j] != INF)
                        adj[i][j] = -INF;
            }
        }


        while (q--) {
            cin >> u >> v;

            if (adj[u][v] == INF)       cout << "Impossible" << endl;
            else if (adj[u][v] == -INF) cout << "-Infinity" << endl;
            else                        cout << adj[u][v] << endl;
        }
        cout << endl;
    }

    return 0;
}
