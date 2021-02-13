#include <bits/stdc++.h>
#include <vector>

using namespace std;

typedef long long ll;

ll n;
vector<vector<ll>> capacity;
vector<vector<ll>> adj;
ll INF = 1e18;

ll bfs(ll s, ll t, vector<ll>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<ll, ll>> q;
    q.push({s, INF});

    while (!q.empty()) {
        ll cur = q.front().first;
        ll flow = q.front().second;
        q.pop();

        for (ll next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                ll new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

ll maxflow(ll s, ll t) {
    ll flow = 0;
    vector<ll> parent(n);
    ll new_flow;

    while ((new_flow = bfs(s, t, parent))) {
        flow += new_flow;
        ll cur = t;
        while (cur != s) {
            ll prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int main() {

    ll m, s, t;
    cin >> n >> m >> s >> t;

    capacity = vector<vector<ll>>(n, vector<ll>(n, 0));
    adj = vector<vector<ll>>(n, vector<ll>());

    ll u, v, c;
    while (cin >> u >> v >> c) {
        adj[u].push_back(v);
        capacity[u][v] += c;
    }

    vector<vector<ll>> initial_capacity = capacity;
    ll flow = maxflow(s, t);

    ll m1 = 0;
    for(ll i=0; i<n; i++) for (ll j=0; j<n; j++) {
        if (initial_capacity[i][j] - capacity[i][j] > 0) m1++;
    }

    cout << n << " " << flow << " " << m1 << endl;
    for(ll i=0; i<n; i++) for (ll j=0; j<n; j++) {
        if (i == j) continue;
        if (initial_capacity[i][j] - capacity[i][j] > 0) {
            cout << i << " " << j << " " <<
                initial_capacity[i][j] - capacity[i][j] << endl;
        }
    }


	return 0;
}
