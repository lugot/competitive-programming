#include<bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> edge;

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
 


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int M, C;
        cin >> M >> C;

        int m = C*(C-1)/2;
        vector<edge> edgelist(m);
        for (edge &e: edgelist){
            int w, u, v;
            cin >>  u >> v >> w;
            e = {w, u, v};
        }

        sort(edgelist.begin(), edgelist.end());

        union_find uf(C);
        int cost = 0;
        int num_taken = 0;

        for (int i=0; i<m; i++) {
            auto [w, u, v] = edgelist[i];
  
            if (!uf.same_set(u, v)) {
                cost += w;
                if (cost > M) break;
                num_taken++;
                if (num_taken == C-1) break;
                uf.union_set(u, v);
            }
        }

        if (cost <= M) cout << "yes" << endl;
        else           cout << "no" << endl;

    }

	return 0;
}
