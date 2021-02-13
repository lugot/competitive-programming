#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> edgelist;
typedef vector<int> vi;
typedef vector<vi> adjlist;

adjlist adj;
edgelist edges;
vi bfslevel;

void bfs(int x) {
    queue<int> q;
    q.push(x);
    bfslevel[x] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        
        for (int v: adj[u]) {
            if (bfslevel[v] == -1) {
                q.push(v);
                bfslevel[v] = (bfslevel[u]+1)%2;
            }
        }
    }
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    int N;
    cin >> N;
    adj = adjlist(N);
    edges = edgelist();
    bfslevel = vi(N, -1);

    int a, b;
    while (cin >> a >> b) {
        a--; b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
        edges.push_back({a,b});
    }

    bfs(0);
    for (auto [a,b]: edges) {
        if (bfslevel[a] == 0) cout << 0 << endl;
        else                  cout << 1 << endl;
    }

	return 0;
}
