#include <bits/stdc++.h>

using namespace std;

typedef int wtype; 

typedef pair<int, wtype> iw;
typedef pair<wtype, int> wi;
typedef vector<iw> viw;
typedef vector<int> vi;
typedef vector<viw> adjlist;

typedef tuple<wtype, int, int, int> wiii;

int n, m;  
adjlist alist;
vi visited;
vi parent;
vi restack;
vi dist;
vi prices;
int INF = 1e9;
int s;

void dijkstra() {

    dist = vi(n, INF);
    parent = vi(n, -1);

    priority_queue<wi, vector<wi>, greater<wi>> pq;
    pq.push({0, s});
    dist[s] = 0;
    parent[s] = s;

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, w]: alist[u]) {

            if (dist[u] + w >= dist[v]) continue;

            dist[v] = dist[u] + w;
            parent[v] = u;
            pq.push({dist[v], v});
        }
    }
}

int main() {
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);

        string a, b;
        ss >> a >> b;

        map<string, int> direct;
        map<int, string> inverse;
        int idx = 0;

        direct[a] = idx;
        inverse[idx++] = a;
        direct[b] = idx;
        inverse[idx++] = b;

        getline(cin, line);
        int n_groups = stoi(line);

        vector<vector<int>> groups(n_groups);
        for (vector<int>& g: groups) {
            getline(cin, line);
            stringstream ss(line);
            
            string name;
            while (ss >> name) {
                if (direct.count(name) == 0) {
                    direct[name] = idx;
                    inverse[idx++] = name;
                }

                g.push_back(direct[name]);
            }
        }

        n = idx;
        alist = adjlist(n);
        for (int g=0; g<n_groups; g++) {
            for (int i=0; i<groups[g].size(); i++) for (int j=0; j<groups[g].size(); j++) {
                if (i == j) continue;

                int u = groups[g][i], v = groups[g][j];

                alist[u].push_back({v, groups[g].size()-2});
                alist[v].push_back({u, groups[g].size()-2});
            }
        }

        s = direct[a];
        dijkstra();

        if (dist[direct[b]] == INF) {
            cout << "impossible" << endl;
            continue;
        }

        vector<int> jumps;
        int act = direct[b];
        while (act = parent[act]) jumps.push_back(act);

        cout << dist[direct[b]] + jumps.size() << " ";

        reverse(jumps.begin(), jumps.end());
        cout << a << " ";
        for (int j: jumps) cout << inverse[j] << " ";
        cout << b << endl;
    }

	return 0;
}
