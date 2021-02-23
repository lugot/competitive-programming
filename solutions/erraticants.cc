#include<bits/stdc++.h>
using namespace std;

typedef int wtype; // change weighttype

typedef pair<int, wtype> iw;
typedef pair<wtype, int> wi;
typedef vector<iw> viw;
typedef vector<int> vi;
typedef vector<viw> adjlist;

int n, m;
adjlist alist;
vi visited;
vi parent;
vi restack;
vi dist;
int INF = 1e9;

int t;

// BFS
void bfs(int x) {
    visited[x] = 1;
    dist[x] = 0;

    queue<int> q;
    q.push(x);

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (auto [v, w]: alist[u]) {
            if (visited[v]) continue;

            visited[v] = 1;
            dist[v] = dist[u] + 1;

            q.push(v);
        }
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		int s;
		cin >> s;

		alist = adjlist(s+1);

		int idx = 0;
		map<pair<int, int>, int> dir;
		map<pair<int, int>, int> inv;

		pair<int, int> pos = {0, 0};
		dir[pos] = idx++;

		int u, v;
		while (s--) {
			char c;
			cin >> c;

			pair<int, int> next;
			if (c == 'N') next = {pos.first, pos.second + 1};
			if (c == 'S') next = {pos.first, pos.second - 1};
			if (c == 'E') next = {pos.first + 1, pos.second};
			if (c == 'W') next = {pos.first - 1, pos.second};

			if (dir.count(next) == 0) dir[next] = idx++;

			u = dir[pos];
			v = dir[next];

			alist[u].push_back({v, 1});
			alist[v].push_back({u, 1});

			pos = next;
		}

		n = alist.size();
		visited = vi(n, 0);
		dist = vi(n, INF);

		bfs(0);

		cout << dist[v] << endl;
	}


    return 0;
}
