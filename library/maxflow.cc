#include <bits/stdc++.h>
#include <vector>

using namespace std;

#define INF 1e9
int n;

int mf, f, s, t;
vector<int> p;

void augment(int v, int min_edge, vector<vector<int>> res) {
    if (v == s) {
        f = min_edge;
        return;
    }
    else if (p[v] != -1) {
        augment(p[v], min(min_edge, res[p[v]][v]), res);
        res[p[v]][v] -= f; res[v][p[v]] += f;
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    // inside int main(): set up ‘res’, ‘s’, and ‘t’ with appropriate values
    int n;
    vector<vector<int>> res; // to initialize

    mf = 0;
    while (1) {

        f = 0;
        // run BFS, compare with the original BFS shown in Section 4.2.2
        vector<int> dist(n, INF);
        dist[s] = 0;

        queue<int> q;
        q.push(s);
        p.assign(n, -1);
         // record the BFS spanning tree, from s to t!
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (u == t) break; // immediately stop BFS if we already reach sink t

            for (int v=0; v<n; v++) {
                 // note: this part is slow
                if (res[u][v] > 0 && dist[v] == INF) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                    p[v] = u;
                }
            }
        }
        augment(t, INF, res);
        if (f == 0) break;
        mf += f;
    }

    printf("%d\n", mf);

	return 0;
}
