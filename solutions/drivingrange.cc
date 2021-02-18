#include<bits/stdc++.h>
using namespace std;

struct union_find {
	vector<int> p, rank, size_of_set;
    int num_sets;

    union_find(int N) { 
        p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i;
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
        if (!same_set(i, j)){ 
            int x = find_set(i), y = find_set(j);
            if (rank[x] > rank[y]) swap(x,y);
            p[x] = y;
            if (rank[x] == rank[y]) rank[y]++;
            size_of_set[y] += size_of_set[x];
            num_sets--;
    }} 
};

typedef long long wtype; // change weighttype

typedef tuple<wtype, int, int> edge;
typedef vector<edge> edgelist;

int n, m;  
edgelist elist;

// KRUSKAL, O(mlogm)
union_find uf(0);
wtype kruskal() {
    wtype ans = 0;

    sort(elist.begin(), elist.end());
    uf = union_find(n);

    for (int i=0; i<m; i++) {
        auto [w, u, v] = elist[i];

        if (uf.same_set(u, v)) continue;

		ans = w;
        uf.union_set(u, v);
    }

	if (uf.num_sets != 1) ans = 0;

    return ans;
}

int main() {

	cin >> n >> m;
	elist = edgelist(m);
	for (auto& [w, a, b]: elist) cin >> a >> b >> w;

	wtype ans = kruskal();

	if (ans == 0) cout << "IMPOSSIBLE" << endl;
	else		  cout << ans << endl;


    return 0;
}
