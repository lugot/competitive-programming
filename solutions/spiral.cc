#include <bits/stdc++.h>
// WARNING: overcomplicated

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

vi circle_length;
vi odds;
vi dist;
int n;

ii num2coord(int n) {

	int j = 0;
	while (n >= circle_length[j]) {
		n -= circle_length[j++];
	}
	j--;

	ii coord = {j, -j};

	if (n == 0) return coord;

	coord = {coord.first + 1, coord.second};
	n--;

	int row_length = (circle_length[j+2] - 4) / 4 - 1;

	coord = {coord.first, coord.second + min(n, row_length-1)};
	n -= min(n, row_length-1);

	coord = {coord.first - min(n, row_length), coord.second};
	n -= min(n, row_length);

	coord = {coord.first, coord.second - min(n, row_length)};
	n -= min(n, row_length);

	coord = {coord.first + min(n, row_length), coord.second};
	n -= min(n, row_length);

	return coord;
}

int coord2num(ii coord) {
	int circle_layer = max(abs(coord.first), abs(coord.second));

	if (circle_layer == 0) return 1;

	int n = (int) pow((circle_layer + circle_layer - 1), 2);

	if (coord.first == circle_layer and coord.second == -circle_layer) {
		return (int) pow((circle_layer + circle_layer + 1), 2);
	}

	int row_length = 2*circle_layer + 1;

	if (coord.first == circle_layer)        n += 0*(row_length - 1) + coord.second + circle_layer;
	else if (coord.second == circle_layer)  n += 1*(row_length - 1) - coord.first  + circle_layer;
	else if (coord.first == -circle_layer)  n += 2*(row_length - 1) - coord.second + circle_layer;
	else if (coord.second == -circle_layer) n += 3*(row_length - 1) + coord.first  + circle_layer;

	return n;
}

bool prime(int n) {
	if (n == 1) return false;
	if (n%2 == 0) return false;

	for (int i=3; i*i<=n; i+=2) {
		if (n%i == 0) return false;
	}

	return true;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	odds.push_back(0);
	for (int i=1; i<10000; i++) {
		odds.push_back(i*2 - 1);
	}
	circle_length.push_back(1);
	for (int i=1; i<odds.size(); i++) {
		circle_length.push_back(odds[i]*4 + 4);
	}

	int x, y, t=1;
	bool found;
	while (cin >> x >> y) {
		cout << "Case " << t++ << ": ";
		dist = vi(10000, -1);

		queue<ii> q;
		dist[x] = 0;
		q.push(num2coord(x));

		while (!q.empty()) {
			auto [i, j] = q.front(); q.pop();

			int act = coord2num({i, j});
			//cout << act << " " << dist[act] << " " << i << " " << j << endl;
			if (act == y) break;

			n = coord2num({i+1, j});
			if (n <= 10000 and !prime(n) and dist[n] == -1) {
				dist[n] = dist[act]+1;
				q.push({i+1, j});
			}
			n = coord2num({i-1, j});
			if (n <= 10000 and !prime(n) and dist[n] == -1) {
				dist[n] = dist[act]+1;
				q.push({i-1, j});
			}
			n = coord2num({i, j+1});
			if (n <= 10000 and !prime(n) and dist[n] == -1) {
				dist[n] = dist[act]+1;
				q.push({i, j+1});
			}
			n = coord2num({i, j-1});
			if (n <= 10000 and !prime(n) and dist[n] == -1) {
				dist[n] = dist[act]+1;
				q.push({i, j-1});
			}
		}

		if (dist[y] != -1) cout << dist[y] << endl;
		else 			   cout << "impossible" << endl;

	}

	return 0;
}
