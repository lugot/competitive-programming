#include <bits/stdc++.h>
#include <future>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int INF = 1e9;

int R, C;

void floodfill(vvi& grid, vii seeds) {

	if (seeds.size() == 0) {
		for (int i=0; i<R; i++) {
			for (int j=0; j<C; j++) {
				if (grid[i][j] == -1) grid[i][j] = INF;
			}
		}
	}

	queue<ii> q;

	int ans = 0;
	for (ii seed: seeds) {
		grid[seed.first][seed.second] = 0;
		q.push(seed);

		ans++;
	}

	int dx[] = {+1,  0, -1,  0};
	int dy[] = { 0, +1,  0,  -1};

	while (!q.empty()) {
		auto [i, j] = q.front(); q.pop();

		for (int k=0; k<4; k++) {
			int x = i + dx[k];
			int y = j + dy[k];

			if (x < 0 or x >= R or y < 0 or y >= C) continue;

			if (grid[x][y] == -1) {
				grid[x][y] = grid[i][j]+1;
				q.push({x, y});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;
	vvi gridJ = vvi(R, vi(C, -2));
	vvi gridF = vvi(R, vi(C, -2));

	ii s;
	vii seeds;
	vii ts;

	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			char c;
			cin >> c;

			if (c == 'J') s = {i, j};
			if (c == 'F') seeds.push_back({i, j});

			if ((i ==0  or j == 0 or i == R-1 or j == C-1) and
					(c != '#' or c != 'F')) {
				ts.push_back({i, j});
			}

			if (c != '#') gridJ[i][j] = gridF[i][j] = -1;
		}
	}

	floodfill(gridF, seeds);
	floodfill(gridJ, {s});

	int ans = INF;

	for (auto [x, y]: ts) {
		if (gridJ[x][y] != -2 and gridJ[x][y] < gridF[x][y]) ans = min(ans, gridJ[x][y]);
	}

	if (ans != INF) cout << ans+1 << endl;
	else 			cout << "IMPOSSIBLE" << endl;

	return 0;
}
