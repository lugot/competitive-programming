#include<bits/stdc++.h>
#include <math.h>
using namespace std;

typedef tuple<double, int, int> edge;

struct union_find {
	vector<int> p, rank, size_of_set;
    int num_sets;

    union_find(int N) { 
        p.assign(N, 0); for (int i=0; i<N; i++) p[i] = i;
        rank.assign(N, 0);
        size_of_set.assign(N, 1);
        num_sets = N;
    }

    int find_set(int i) {
        return (p[i] == i) ? i : (p[i] = find_set(p[i])); 
    }

    bool same_set(int i, int j) {
        return find_set(i) == find_set(j);
    }

    int set_size(int i) {
        return size_of_set[find_set(i)];
    }

    void union_set(int i, int j) {
        if (same_set(i, j)) return;

        int x = find_set(i), y = find_set(j);
        if (rank[x] > rank[y]) swap(x, y);
        p[x] = y;
        if (rank[x] == rank[y]) rank[y]++;
        size_of_set[y] += size_of_set[x];
        num_sets--;
    }
};
 
struct freckle {
    double X, Y;
};

double dist (double a, double b, double c, double d) {
    return hypot(c-a, d-b);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<freckle> freckles(n);
        for (freckle &a: freckles) cin >> a.X >> a.Y;

        vector<edge> edgelist;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                freckle a1 = freckles[i];
                freckle a2 = freckles[j];

                edgelist.push_back({dist(a1.X, a1.Y, a2.X, a2.Y), i, j});
            }
        }

        sort(edgelist.begin(), edgelist.end());

        union_find uf(n);
        double cost = 0.0;
        int num_taken = 0;

        int m = edgelist.size();
        for (int i=0; i<m; i++) {
            auto [w, u, v] = edgelist[i];

            if (!uf.same_set(u, v)) {
                cost += w;
                num_taken++;
                //if (num_taken == C-1) break;
                uf.union_set(u, v);
            }
        }

        cout << fixed << setprecision(2) << cost << endl << endl;

    }

	return 0;
}
