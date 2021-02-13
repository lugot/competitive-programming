#include <bits/stdc++.h>

using namespace std;

/*
 *this is the shittiest and overcomplicated piece of code ever made, pls skip...
 *btw it's correct
 */

typedef pair<int, int> ii;

int N, M;
vector<vector<char>> b;
ii Vpos, Jpos;
vector<ii> Tpos;
vector<vector<int>> cost;
vector<vector<int>> visited;
vector<ii> frontier;
int INF = 1e9;

void printboard() {
	for (vector<char> row: b) {
		for (char c: row) cout << c;
		cout << endl;
	}
}
void printcost() {
	for (vector<int> row: cost) {
		for (int c: row) cout << c;
		cout << endl;
	}
}
int l1 (ii a, ii b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}
int legal(int x, int y) {
	if (x >= 0 and x < N and y >= 0 and y < M) return 1;
	return 0;
}
int floodfill (int act_cost, int& max_frontier) {
	queue<ii> q;
	for (ii pos: frontier) {
		q.push(pos);
		visited[pos.first][pos.second] = 1;
	}
	frontier.clear();

	int dirx[] = { 0, -1, 0, +1};
	int diry[] = {+1,  0, -1, 0};

	max_frontier = 0;
	while (!q.empty()) {
		auto [i, j] = q.front(); q.pop();

		for (int k=0; k<4; k++) {
			int x = i + dirx[k], y = j + diry[k];
			
			if (!legal(x, y)) continue;
			if (visited[x][y]) continue;
			if (cost[x][y] < act_cost) {
				max_frontier = max(max_frontier, cost[x][y]);
				frontier.push_back({x, y});
				continue;
			}

			visited[x][y] = 1;
			q.push({x, y});

			if (x == Jpos.first and y == Jpos.second) {
				int ans = INF;
				for (int i=0; i<N; i++) for (int j=0; j<M; j++) {
					if (!visited[i][j]) continue;

					ans = min(ans, cost[i][j]);
				}
				max_frontier = ans;

				return 1;
			}
		}

	}

	return 0;
}
int floodcost(ii start) {
	vector<vector<int>> visited(N, vector<int>(M, 0));

	queue<ii> q;
	q.push(start);
	visited[start.first][start.second] = 1;

	int dirx[] = { 0, -1, 0, +1};
	int diry[] = {+1,  0, -1, 0};

	int finish = 0;
	int ans = INF;
	while (!q.empty()) {
		auto [i, j] = q.front(); q.pop();

		for (int k=0; k<4; k++) {
			int x = i + dirx[k], y = j + diry[k];
			
			if (!legal(x, y)) continue;
			if (visited[x][y]) continue;
			if (b[x][y] == '+') {
				ans = min(ans, l1(start, {x, y}));
				finish = 1;
			}

			visited[x][y] = 1;
			if (!finish) q.push({x, y});
		}

	}

	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	b = vector<vector<char>>(N, vector<char>(M, '.'));

	for (int i=0; i<N; i++) for (int j=0; j<M; j++) {
		cin >> b[i][j];

		if (b[i][j] == 'J') Jpos = {i, j};
		if (b[i][j] == 'V') Vpos = {i, j};
		if (b[i][j] == '+') Tpos.push_back({i, j});
	}
	//printboard();

	cost = vector<vector<int>>(N, vector<int>(M, INF));
	for (int i=0; i<N; i++) for (int j=0; j<M; j++) {
		if (b[i][j] == '+') {
			cost[i][j] = 0;
			continue;
		}
		cost[i][j] = floodcost({i, j});
	}
	//printcost();

	int act_cost = cost[Vpos.first][Vpos.second];
	visited = vector<vector<int>>(N, vector<int>(M, 0));
	frontier.push_back(Vpos);
	while (!floodfill(act_cost, act_cost));

	cout << act_cost << endl;

	return 0;
}
