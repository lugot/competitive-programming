#include <algorithm>
#include <bits/stdc++.h>
#include <strings.h>
#include <vector>

using namespace std;

#define INF 1e6

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<int, int> ii;

int t;
int w, h;
//char table[1010][1010];
vector<vector<char>> table(1010, vector<char>(1010, 'X'));

int exit(int i, int j) {
    if ((i == 0 or i == h-1) or (j == 0 or j == w-1) and 
        table[i][j] == '.') return 1;

    return 0;
}
int bound(int i, int j) {
    if ((i >= 0 and i < h) and (j >= 0 and j < w)) return 1;
    return 0;
}

int dirx[] = {0, 1, 0, -1};
int diry[] = {1, 0, -1, 0};

bool bfscost(ii u, vector<vector<int>>& cost) {
    queue<pair<int, ii>> q;
    q.push({0, u});

    vector<vector<int>> visited(h, vector<int>(w, 0));
    visited[u.first][u.second] = 1;
    cost[u.first][u.second] = 0;
    bool solvable = false;
    if (exit(u.first, u.second)) solvable = true;

    while (!q.empty()) {
        auto [c, u] = q.front(); q.pop();
        auto [i, j] = u;

        for (int k=0; k<4; k++) {
            int next_i = i+diry[k];
            int next_j = j+dirx[k];

            if (!bound(next_i, next_j)) continue;
            if (visited[next_i][next_j]) continue;
            if (table[next_i][next_j] != '.') continue;
            if (exit(next_i, next_j)) solvable = true;

            visited[next_i][next_j] = 1;
            cost[next_i][next_j] = min(cost[next_i][next_j], c+1);
            q.push({c+1, {next_i, next_j}});
        }
    }

    return solvable;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> w >> h;

        ii start;
        vector<ii> fires;
        vector<ii> exits;

        for (int i=0; i<h; i++) {
            string s;
            cin >> s;

            for (int j=0; j<w; j++) {
                table[i][j] = s[j];

                if (s[j] == '@') {
                    start = {i, j};
                    table[i][j] = '.';
                }
                if (s[j] == '*') fires.push_back({i, j});
                if (exit(i, j)) exits.push_back({i, j});
            }
        }

        vector<vector<int>> fcost(h, vector<int>(w, INF));
        vector<vector<int>> scost(h, vector<int>(w, INF));

        if (bfscost(start, scost) == false) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        for (ii f: fires) bfscost(f, fcost);

        int ans = INF;
        for (auto [i, j]: exits) {
            if (scost[i][j] < fcost[i][j]) ans = min(ans, scost[i][j]);
        }

        if (ans == INF) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        cout << ans+1 << endl;
    }


	return 0;
}
