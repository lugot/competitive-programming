#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int n;
vector<ii> res, com;

int l1(ii a, ii b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	string line;
	getline(cin, line);

	n = stoi(line);

	vector<vector<int>> board(n, vector<int>(n, 0));
	vector<vector<int>> visited(n, vector<int>(n, 0));
	vector<vector<int>> dist(n, vector<int>(n, 1e9));

	queue<ii> q;

	for (int i=0; i<n; i++) {
		getline(cin, line);

		for (int j=0; j<n; j++) {
			int cell = line[j] - '0';
			board[i][j] = cell;

			if (cell == 3) {
				q.push({i, j});
				dist[i][j] = 0;
			}
		}
	}

	int dx[4] = {1, 0, -1,  0};
	int dy[4] = {0, 1,  0, -1};

	int ans = 0;
	while (!q.empty()) {
		auto [i, j] = q.front(); q.pop();

		if (visited[i][j]) continue;
		visited[i][j] = 1;

		if (board[i][j] == 1) ans = max(ans, dist[i][j]);

		for(int k=0; k<4; k++) {
			int x = i + dx[k];
			int y = j + dy[k];

			if(x< 0 or x>=n or y<0 or y>=n) continue;

			dist[x][y] = min(dist[x][y], (dist[i][j] + 1));

			if(!visited[x][y]) q.push({x, y});
		}
	}

	cout << ans << endl;


	return 0;
}
