#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> adjlist;

adjlist adj;
vi visited;
vi bfslevel;
int numcc;
int oddcycle;

void cc(int u) {
    queue<int> q;
    q.push(u);
    visited[u] = numcc;
    bfslevel[u] = 0;

    while (!q.empty()) {
        int v = q.front(); q.pop();

        for (int k: adj[v]) {
            if (visited[k] == -1) {
                visited[k] = numcc;
                bfslevel[k] = bfslevel[v] + 1;

                q.push(k);
            }
            else if ((bfslevel[v]%2) == (bfslevel[k]%2)) oddcycle = 1;
        }
    }
    numcc++;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    int N, M;
    cin >> N >> M;

    adj = adjlist(N);
    visited = vi(N, -1);
    bfslevel = vi(N, -1);
    vi alone = vi(N, 1);

    int u,v;
    while (cin >> u >> v) {
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);

        alone[v] = alone[u] = 0;
    }

    for (int i=0; i<N; i++) {
        if (alone[i]) visited[i] = numcc++;
    }

    for (int i=0; i<N; i++) {
        if (visited[i] == -1) {
            cc(i);
            //i = 0; ma sono coglione o cosa?
        }
    }

    if (oddcycle) cout << numcc-1 << endl;
    else          cout << numcc << endl;

    return 0;
}
