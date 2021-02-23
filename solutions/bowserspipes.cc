#include <bits/stdc++.h>
#include <cstring>

using namespace std;

typedef double wtype; // change weighttype

typedef pair<int, wtype> iw;
typedef pair<wtype, int> wi;
typedef pair<int, int> ii;
typedef vector<iw> viw;
typedef vector<int> vi;
typedef vector<viw> adjlist;

int n, m;
adjlist alist;
vi visited;
vi dist;

vi coin_rooms;

int A;
vi rooms;
vi ans;
vi ans_pathlen;

void bfs(int x, int root) {
    visited[x] = 1;

    queue<ii> q;
    q.push({x, 0});

    while (!q.empty()) {
        auto [u, l] = q.front(); q.pop();

        for (auto [v, w]: alist[u]) {

            if (visited[v] != -1) continue;

            if (alist[v].size() == 0) {
                if (ans_pathlen[root] == l+1) ans[root] = min(ans[root], v);
                if (ans_pathlen[root] > l+1) {
                    ans[root] = v;
                    ans_pathlen[root] = l+1;
                }
            }
            visited[v] = root;
            q.push({v, l+1});
        }
    }
}

int main() {

    cin >> n;
    alist = adjlist(n);
    ans = vi(n, -1);
    ans_pathlen = vi(n, 1e9);
    visited = vi(n, -1);

    for (int i=0; i<n; i++) {
        int F;
        cin >> F;

        if (F != -1) alist[F].push_back({i, 1});
        else         coin_rooms.push_back(i);
    }

    for (viw& adiacency: alist) sort(adiacency.begin(), adiacency.end());
    for (int coin_room: coin_rooms) bfs(coin_room, coin_room);

    cin >> A;
    while (A--) {
        int D;
        cin >> D;

        cout << ans[visited[D]] << endl;;
    }

    return 0;
}
