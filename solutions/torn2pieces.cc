#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
#include <sstream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> adjlist;

adjlist adj;
vi visited;
vi parent;

void bfs(int x, int t) {

    queue<int> q;
    q.push(x);
    visited[x] = 1;
    parent[x] = x;

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (int v: adj[u]) {
            if (!visited[v]) {
                visited[v] = 1;
                parent[v] = u;

                if (v == t) return;
                q.push(v);
            }
        }
    }

    return;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    int N;
    string line;
    getline(cin, line);
    N = stoi(line);
    
    map<string, int> direct;
    map<int, string> inverse;

    adj = adjlist(32);
    visited = vi(32, 0);
    parent = vi(32, -1);

    string s1, s2;
    int nodeidx = 0;
    while (N--) {
        getline(cin, line);
        stringstream ss(line);
        
        ss >> s1;

        while (ss >> s2) {
            if (direct.count(s1) == 0) {
                direct[s1] = nodeidx;
                inverse[nodeidx++] = s1;
            }
            if (direct.count(s2) == 0) {
                direct[s2] = nodeidx;
                inverse[nodeidx++] = s2;
            }

            int a = direct[s1];
            int b = direct[s2];

            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }

    string s, t;
    getline(cin, line);
    stringstream ss(line);
    ss >> s >> t;
    if (direct.count(s) == 0) {
        direct[s] = nodeidx;
        inverse[nodeidx++] = s;
    }
    if (direct.count(t) == 0) {
        direct[t] = nodeidx;
        inverse[nodeidx++] = t;
    }


    bfs(direct[s], direct[t]);

    if (!visited[direct[t]]) {
        cout << "no route found" << endl;
        return 0;
    }
    
    vector<string> ans;
    int act = direct[t];
    while (act != direct[s]) {
        ans.push_back(inverse[act]);
        act = parent[act];
    }
    ans.push_back(inverse[act]);

    reverse(ans.begin(), ans.end());
    for (string s: ans) cout << s << " ";
    cout << endl;

	return 0;
}
