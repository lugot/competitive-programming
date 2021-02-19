#include <bits/stdc++.h>
#include <vector>

using namespace std;

typedef int wtype; 

typedef pair<int, wtype> iw;
typedef pair<wtype, int> wi;
typedef vector<iw> viw;
typedef vector<int> vi;
typedef vector<viw> adjlist;
typedef pair<int, int> ii;

int n, m;  
adjlist alist;
vi visited;
vi parent;
vi dist;
int INF = 1e9;

int main() {

    int T, t;
    cin >> T;

    while (T--) {
        cin >> n >> t;
        vector<int> buttons(n);
        for (auto& b: buttons) cin >> b;

        vector<int> state(3610, INF);
        state[0] = 0;

        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            auto u = q.front(); q.pop();

            for (int b: buttons) {
                int next = max(0, min(3600, u+b));

                if (state[next] > state[u]+1) {
                    state[next] = state[u]+1;
                    q.push(next);
                }
            }
        }

        for (int j=t; j <= 3600; j++) {
            if (state[j] != INF){
                cout << state[j] << " " << j-t << endl;
                break;
            }
        }

    }

	return 0;
}
