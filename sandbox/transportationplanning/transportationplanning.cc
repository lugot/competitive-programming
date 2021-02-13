#include <bits/stdc++.h>
#include <iomanip>
#include <vector>

#define INF 1e9

using namespace std;

struct point {
    double x, y;
};
double dist2(point a, point b){
    return hypot(a.x - b.x, a.y - b.y);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    int n;
    while (cin >> n) {
        if (n == 0) break;

        vector<point> loc(n);
        for (point& p: loc) cin >> p.x >> p.y;

        vector<vector<double>> adj(n, vector<double>(n, INF));
        for (int i=0; i<n; i++) adj[i][i] = 0;

        int m;
        cin >> m;

        int i1, i2;
        while (m--) {
            cin >> i1 >> i2;
            adj[i1][i2] = min(dist2(loc[i1], loc[i2]), adj[i1][i2]);
            adj[i2][i1] = min(dist2(loc[i1], loc[i2]), adj[i2][i1]);
        }


        vector<vector<double>> dist(n, vector<double>(n, INF));
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) dist[i][j] = adj[i][j];
        vector<vector<int>> p(n, vector<int>(n, INF));
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) p[i][j] = i;
 
        for (int k=0; k<n; k++) {
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    if (dist[i][j] > dist[i][k] + dist[k][j] && dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }

        double ans1 = 0.0;
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
            if (dist[i][j] != INF) ans1 += dist[i][j];
        }


        double min_cost = -INF;
        int mini, minj;
        int min_path_length;
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
            if (i == j) continue;

            if (adj[i][j] == INF && min_cost < dist[i][j]) {
                min_cost = dist[i][j];
                mini = i;
                minj = j;
                
                min_path_length = 0;
                int newj = j;
                while (i != newj) {
                    newj = p[i][newj];
                    min_path_length++;
                }
            }
        }
        if (min_cost == -INF) {
            cout  << "no addition reduces " << ans1/2 << endl;
            continue;
        }


        for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
            if (i == j) continue;
            if (dist[i][j] != min_cost) continue;

            int act_path_length = 0;
                int newj = j;
                while (i != newj) {
                    newj = p[i][newj];
                    act_path_length++;
                }

                if (act_path_length < min_path_length) {
                    min_path_length = act_path_length;
                    mini = i;
                    minj = j;
                }
        }




        double ans2 = 0.0;
        adj[mini][minj] = dist2(loc[mini], loc[minj]);
        adj[minj][mini] = dist2(loc[mini], loc[minj]);
        for (int k=0; k<n; k++) {
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    if (adj[i][j] > adj[i][k] + adj[k][j] && adj[i][k] < INF && adj[k][j] < INF)
                        adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
            if (adj[i][j] != INF) ans2 += adj[i][j];
        }

        cout << "adding " << mini << " " << minj;
        cout << " reduces " << fixed << setprecision(8) << ans1/2;
        cout << " to " << fixed << setprecision(8) << ans2/2 << endl;
    }

    return 0;
}
