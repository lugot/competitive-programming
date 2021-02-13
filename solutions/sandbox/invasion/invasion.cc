#include <bits/stdc++.h>
#include <queue>

#define INF 1e9

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vector<ii>> adjlist;
typedef vector<int> vi;

adjlist adj;
vi dist;
vi is_base;
vi bases;
vi dyn_dist;

int N, M, A, K;
int T1, T2, D;
int B;

int dijkstra(int s) {
    dist = vi(N, INF);

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, s});
    dist[s] = 0;

    while (!pq.empty()) {
        auto [w1, u] = pq.top(); pq.pop();

        if (w1 > dist[u]) continue;

        for (auto [v, w2]: adj[u]) {
            if (dist[u] + w2 < dist[v]) {
                dist[v] = dist[u] + w2;
                pq.push({dist[v], v});
            }
        }
    }

    int ans = 0;
    for (int i=0; i<N; i++) {
        dyn_dist[i] = min(dyn_dist[i], dist[i]);

        if (dyn_dist[i] >= K) ans++;
    }

    return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    while (cin >> N >> M >> A >> K) {
        if (N == 0) break;

        adj = adjlist(N);

        while (M--) {
            cin >> T1 >> T2 >> D;
            T1--; T2--;

            adj[T1].push_back({T2, D});
            adj[T2].push_back({T1, D});
        }

        dyn_dist = vi(N, INF);
        while (A--) {
            cin >> B;
            B--;

            cout << dijkstra(B) << endl;
        }
        cout << endl;
/*
 *        dyn_dist = vi(N, INF);
 *        if (false) {
 *        //if (A < N-A) {
 *            dyn_dist = vi(N, INF);
 *            while (A--) {
 *                cin >> B;
 *                B--;
 *
 *                cout << dijkstra(B) << endl;
 *            }
 *            cout << endl;
 *        }
 *        else {
 *            is_base = vi(N, 0);
 *            bases = vi();
 *
 *            while (A--) {
 *                cin >> B;
 *                B--;
 *
 *                is_base[B] = 1;
 *                bases.push_back(B);
 *            }
 *            A = bases.size();
 *
 *            vi ans = vi(A, 0);
 *            for (int i=0; i<N; i++) {
 *                if (!is_base[i]) {
 *                    dijkstra(i);
 *
 *                    for (int j=0; j<A; j++) if (dist[bases[j]] >= K) ans[j]++;
 *                }
 *            }
 *
 *            for (int a: ans) cout << a << endl;
 *            cout << endl;
 *        }
 */

    }

	return 0;
}
