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

typedef int wtype; // change weighttype

typedef tuple<wtype, int, int> edge;
typedef vector<edge> edgelist;
typedef vector<pair<int, int>> kruskal_tree;

int n, m;  
edgelist elist;

// KRUSKAL, O(mlogm)
union_find uf(0);
kruskal_tree ktree;
wtype kruskal() {
    wtype mst_cost = 0;

    sort(elist.begin(), elist.end());
    uf = union_find(n);
	ktree = kruskal_tree(0);

    for (auto [w, u, v]: elist) {

        if (uf.same_set(u, v)) continue;

		ktree.push_back({u, v});
        mst_cost += w;
        uf.union_set(u, v);
    }

    return mst_cost;
}

int diff(string a, string b) {
	int ans = 0;
	for (int i=0; i<a.length(); i++) if (a[i] != b[i]) ans++;

	return ans;
}

int main() {

	int k;
	cin >> n >> k;

	vector<string> samples(n);
	for (string& s: samples) cin >> s;

	for (int i=0; i<n; i++) for (int j=i+1; j<n; j++) {
		elist.push_back({diff(samples[i], samples[j]), i, j});
	}

	cout << kruskal() << endl;
	for (auto [u, v]: ktree) cout << u << " " << v << endl;


    return 0;
}
