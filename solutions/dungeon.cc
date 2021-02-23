#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef tuple<int, int, int> iii;

int L, R, C;
iii s, t;
vvvi board;

int dx[] = {+1,  0, -1,  0,  0,  0};
int dy[] = { 0, +1,  0, -1,  0,  0};
int dz[] = { 0,  0,  0,  0, +1, -1};

int floodfill() {

	queue<iii> q;
	q.push(s);

	while (!q.empty()) {
		auto [k, i, j] = q.front(); q.pop();

		for (int w=0; w<6; w++) {
			int z = k + dz[w];
			int x = i + dx[w];
			int y = j + dy[w];

			if (z<0 or z>=L or x<0 or x>=R or y<0 or y>=C) continue;

			if (board[z][x][y] == 0) {
				board[z][x][y] = board[k][i][j]+1;
				q.push({z, x, y});
			}
		}
	}

	auto [z, x, y] = t;
	return board[z][x][y];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> L >>  R >> C) {
		if (L == 0) break;

		board = vvvi(L, vvi(R, vi(C, 0)));

		char in;
		for (int z=0; z<L; z++) {
			for (int x=0; x<R; x++) {
				for (int y=0; y<C; y++) {
					cin >> in;

					if (in == '#') board[z][x][y] = -1;
					if (in == 'S') s = {z, x, y};
					if (in == 'E') t = {z, x, y};
				}
			}
		}

		int ans = floodfill();

		if (ans == 0) cout << "Trapped!" << endl;
		else          cout << "Escaped in " << ans << " minute(s)." << endl;
	}

	return 0;
}
