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
vi dist;
int INF = 1e9;

int idx = 0;
map<string, int> direct;
map<int, string> inverse;
map<pair<int, int>, int> citations;
vector<int> authors;

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

	string line;
	while (getline(cin, line)) {
		stringstream ss(line);

		string author, coauthor;
		ss >> author;

		if (direct.count(author) == 0) {
			direct[author] = idx;
			inverse[idx++] = author;
		}

		authors.push_back(direct[author]);

		while (ss >> coauthor) {

			if (direct.count(coauthor) == 0) {
				direct[coauthor] = idx;
				inverse[idx++] = coauthor;
			}

			// this map is useless, i misread the problem statement
			citations[{direct[author], direct[coauthor]}]++;
		}
	}

	n = idx;
	alist = adjlist(n);
	for (pair<pair<int, int>, int> cit: citations) {
		int c = cit.second;
		auto [a1, a2] = cit.first;

		alist[a1].push_back({a2, 1});
		alist[a2].push_back({a1, 1});
	}

	for (int a: authors) {
		visited = vi(n, 0);
		dist = vi(n, INF);

		if (a == 0) cout << inverse[a] << " 0" << endl;
		else {
			bfs(a);
			cout << inverse[a] << " ";
			if (dist[direct["PAUL_ERDOS"]] != INF) {
				cout << dist[direct["PAUL_ERDOS"]] << endl;
			}
			else 				cout << "no-connection" << endl;
		}
	}

    return 0;
}
