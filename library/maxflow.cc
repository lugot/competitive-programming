#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n;
vector<vector<ll>> capacity;
vector<vector<ll>> adj;
ll INF = 1e9;

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

    ll m;
    cin >> n >> m;

    capacity = vector<vector<ll>>(n, vector<ll>(n, 0));
    adj = vector<vector<ll>>(n, vector<ll>());

    ll u, v, c;
    while (cin >> u >> v >> c) {
        adj[u-1].push_back(v-1);
        capacity[u-1][v-1] += c;
    }

    ll flow = maxflow(0, n-1);
    cout << flow << endl;


	return 0;
}
