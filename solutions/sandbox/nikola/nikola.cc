#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
#include <vector>

#define INF 1e9

using namespace std;

typedef tuple<int, int, int> iii;
//struct iii {
    //int a, b, c;
//};

int N;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> N;
    vector<int> t(N, INF);

    vector<int> cost(N);
    for (int& c: cost) cin >> c;

    queue<iii> q;
    q.push({1, 1, cost[1]});
    t[1] = cost[1];

    int ans = INF;
    while (!q.empty()) {
        auto [s, j, c] = q.front(); q.pop();

        if (c > ans - cost[N-1]) continue;

        //cout << "square: " << s << " jump: " << j << " act cost: " << c << endl;

        if (s == N-1) ans = min(ans, c);

        int target;
        target = s + j+1;
        if (target < N ) { //and t[target] > c + cost[target]) {
            t[target] = min(t[target], c + cost[target]);
            q.push({target, j+1, c + cost[target]});
        }
        target = s - j;
        if (target >= 0 ) { //and t[target] > c + cost[target]) {
            t[target] = min(t[target], c + cost[target]);
            q.push({target, j, c + cost[target]});
        }
    }

    cout << t[N-1] << endl;



	return 0;
}
