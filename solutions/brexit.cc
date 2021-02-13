#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<int, int> ii;

vector<vector<int>> adj;

int topodelete(int L, int X) { 
    if (L == X) return 1;

    int n = adj.size();

    vector<int> deg(n, 0); 
    for (int u=0; u<n; u++) deg[u] = adj[u].size();

    vector<int> original_deg = deg;
  
	priority_queue<ii, vector<ii>> pq; 
    pq.push({deg[L], L});
    
    vector<bool> out(n, false);
    out[L] = true;

    while (!pq.empty()) {
        auto [dummy, v] = pq.top(); pq.pop();
        out[v] = true;

        //cout << v << endl;
        //for (int i=0; i<n; i++) cout << i << " " << deg[i] << endl;
        //cout << endl;

        for (int u: adj[v]) {
            if (out[u]) continue;

            deg[u]--;
            if (2*deg[u] <= original_deg[u]) {
                if (u == X) return 1;

                pq.push({deg[u], u});
            }
        }
    }
    return 0;
} 


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    int C, P, X, L;
    cin >> C >> P >> X >> L;
    L--; X--;

    adj = vector<vector<int>>(C);
    int A, B;
    while (P--) {
        cin >> A >> B;
        A--; B--;

        adj[A].push_back(B);
        adj[B].push_back(A);
    }

    if (topodelete(L, X)) cout << "leave" << endl;
    else                  cout << "stay" << endl;


	return 0;
}
