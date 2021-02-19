#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int INF = 1e9;
vector<int> dist(1e6+3, INF);

int f, s, g, u, d;
int main(){

	cin >> f >> s >> g >> u >> d;

	if (s == g) {
		cout << '0' << endl;
		return 0;
	}

	queue<int> q;
	q.push(s);
	dist[s] = 0;

	while (!q.empty()) {
		int act = q.front(); q.pop();

		if (act + u <= f and dist[act+u] > dist[act]+1) {
			dist[act+u] = dist[act]+1;
			q.push(act+u);
		}
		if (act - d > 0 and dist[act-d] > dist[act]+1) {
			dist[act-d] = dist[act]+1;
			q.push(act-d);
		}
	}

	if (dist[g] == INF) cout << "use the stairs" << endl;
	else				cout << dist[g] << endl;


	return 0;
}
