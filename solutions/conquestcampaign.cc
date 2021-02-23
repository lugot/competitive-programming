#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int R, C, N;
vii seeds;

int dx[] = {+1,  0, -1,  0};
int dy[] = { 0, +1,  0,  -1};

int floodfill() {
	vector<vector<int>> board(R, vector<int>(C, -1));

	queue<ii> q;
	for (ii seed: seeds) q.push(seed);
	for (auto [i, j]: seeds) board[i][j] = 0;

	while (!q.empty()) {
		auto [i, j] = q.front(); q.pop();

		for (int k=0; k<4; k++) {
			int x = i + dx[k];
			int y = j + dy[k];

			if (x<0 or x>=R or y<0 or y>=C) continue;

			if (board[x][y] == -1) {
				board[x][y] = board[i][j]+1;
				q.push({x, y});
			}
		}
	}

	int ans = 0;
	for (auto row: board) for (int cell: row) {
		ans = max(ans, cell);
	}

	return ans+1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C >> N;
	seeds = vii(N);

	for (auto& [x, y]: seeds) cin >> x >> y;
	for (auto& [x, y]: seeds) x--, y--;

	cout << floodfill() << endl;

	return 0;
}
