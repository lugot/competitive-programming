#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<int, int> ii;

vector<int> visited; 
vector<int> ts;
vector<int> lab;
vector<vector<int>> adj;
vector<int> deg;

void process(queue<int>& q, queue<int>& p) {
    while (!q.empty()) {
        int v = q.front(); q.pop();
        //cout << v << endl;

        for (int u: adj[v]) {
            if (visited[u]) continue;

            deg[u]--;
            if (deg[u] != 0) continue;

            if (lab[u] == lab[v]) q.push(u);
            else                  p.push(u);
            visited[v] = 1;
        }
    }
}
int toposort(int order) { 
    int n = adj.size();

    deg = vector<int>(n, 0); 
    for (int u=0; u<n; u++) {
        for (int v: adj[u]) deg[v]++;
    }

    queue<int> q1, q2, temp;
    for (int i=0; i<n; i++) {
        if (deg[i] > 0) continue;

        if (lab[i]) q1.push(i);
        else        q2.push(i);
    }
    if (order) {
        temp = q1;
        q1 = q2;
        q2 = temp;
    }
    visited = vector<int>(n, 0);
    
    int ans = 0;
    while (!q1.empty() or !q2.empty()) {

        if (!q1.empty()) process(q1, q2);
        else             process(q2, q1);

        ans++;
    }


    return ans-1;
} 

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;
        
        lab = vector<int>(n);
        for (int& l: lab) cin >> l;
        for (int& l: lab) l--;

        adj = vector<vector<int>>(n);

        int i, j;
        while (m--) {
            cin >> i >> j;
            i--; j--;

            adj[i].push_back(j);
        }
        

        cout << min(toposort(0), toposort(1)) << endl;
    }


	return 0;
}
