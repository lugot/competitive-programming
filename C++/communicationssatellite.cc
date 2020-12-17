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
 
struct ant {
    int X, Y, R;
};

double dist (double a, double b, double c, double d) {
    return hypot(c-a, d-b);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    int N;
    cin >> N;
    vector<ant> ants(N);
    for (ant &a: ants) cin >> a.X >> a.Y >> a.R;

    vector<edge> edgelist;
    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++) {
            ant a1 = ants[i];
            ant a2 = ants[j];

            edgelist.push_back({dist(a1.X, a1.Y, a2.X, a2.Y) - a1.R - a2.R,
                    i, j});
        }
    }

    sort(edgelist.begin(), edgelist.end());

    union_find uf(N);
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

    cout << fixed << setprecision(8) << cost << endl;


	return 0;
}
