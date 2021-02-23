#include <bits/stdc++.h>
#include <future>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;


int t;
int X, Y, T, L, W;

vvi grid;
vii leaks;

void printgrid() {
	for (vi line: grid) {
		for (int cell: line) {
			if (cell == -1) cout << "#";
			else 			cout << cell;
		}
		cout << endl;
	}
}

int floodfill() {
	queue<ii> q;

	int ans = 0;
	for (ii leak: leaks) {
		grid[leak.first][leak.second] = 1;
		q.push(leak);

		ans++;
	}

	int dx[] = {+1,  0, -1,  0};
	int dy[] = { 0, +1,  0,  -1};

	while (!q.empty()) {
		auto [i, j] = q.front(); q.pop();

		if (grid[i][j] == T) continue;

		for (int k=0; k<4; k++) {
			int x = i + dx[k];
			int y = j + dy[k];

			if (x < 0 or x >= X or y < 0 or y >= Y) continue;

			if (grid[x][y] == 0) {
				grid[x][y] = grid[i][j]+1;
				q.push({x, y});

				ans++;
			}

		}
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> Y) {
		if (Y == -1) break;
		cin >> X >> T >> L >> W;

		grid = vvi(X, vi(Y, 0));

		leaks = vii(L);
		for (auto& [x, y]: leaks) cin >> y >> x;
		for (auto& [x, y]: leaks) {
			x = X - x;
			y--;
		}

		while (W--) {
			int x1, y1, x2, y2;
			cin >> y1 >> x1 >> y2 >> x2;
			y1--; y2--;
			x1 = X - x1;
			x2 = X - x2;

			if (x1 == x2) {
				if (y1 > y2) swap(y1, y2);
				for (; y1 < y2; y1++) grid[x1][y1] = -1;
			}
			if (y1 == y2) {
				if (x1 > x2) swap(x1, x2);
				for (; x1 < x2; x1++) grid[x1][y1] = -1;
			}
			if (y1 - x1 == y2 - x2) {
				if (x1 > x2) swap(x1, x2);
				if (y1 > y2) swap(y1, y2);
				for (; x1 <= x2 and y1 <= y2; x1++, y1++) grid[x1][y1] = -1;
			}
			if (y1 - x1 != y2 - x2) {
				if (x1 > x2) swap(x1, x2);
				if (y1 < y2) swap(y1, y2);
				for (; x1 <= x2 and y1 >= y2; x1++, y1--) grid[x1][y1] = -1;
			}
		}
		cout << floodfill() << endl;
		//printgrid();

	}



	return 0;
}
