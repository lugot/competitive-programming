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

typedef double wtype; // change weighttype

typedef tuple<wtype, int, int> edge;
typedef vector<edge> edgelist;

typedef pair<int, wtype> iw;
typedef pair<wtype, int> wi;
typedef vector<iw> viw;
typedef vector<int> vi;
typedef vector<viw> adjlist;

int n, m;  
edgelist elist;
adjlist alist;

// KRUSKAL, O(mlogm)
union_find uf(0);
wtype kruskal() {
    wtype mst_cost = 0;

    sort(elist.begin(), elist.end());
    uf = union_find(n);

    for (auto [w, u, v]: elist) {

        if (uf.same_set(u, v)) continue;

        mst_cost += w;
        uf.union_set(u, v);
    }

    return mst_cost;
}

// PRIM, O(mlogm)
vi taken;
priority_queue<wi, vector<wi>, greater<wi>> pq;

void process(int x) {
    taken[x] = 1;
    for (auto [u, w]: alist[x]) {
        if (taken[u]) continue; 
        pq.push({w, u});
    } 
}
wtype prim() { // O(mlogm)
    wtype mst_cost = 0;

    taken = vi(n, 0);
    int num_taken = 0;

    process(0);

    while (!pq.empty() and num_taken < n) { 
        auto [w, u] = pq.top(); pq.pop();

        if (taken[u]) continue;

        mst_cost += w;
        process(u);

        num_taken++;
    }

    return mst_cost;
}

double l2(pair<double, double> i1, pair<double, double> i2) {
	auto [x1, y1] = i1;
	auto [x2, y2] = i2;

	return hypot(x1-x2, y1-y2);
}
int main() {

	int t;
	cin >> t;

	while (t--) {
		cin >> n;

		vector<pair<double, double>> islands(n);
		for (auto& [x, y]: islands) cin >> x >> y;

		alist = adjlist(n);
        elist = edgelist(0);
		for (int i=0; i<n; i++) for (int j=i+1; j<n; j++) {
			wtype dist = l2(islands[i], islands[j]);

			alist[i].push_back({j, dist});
			alist[j].push_back({i, dist});
			elist.push_back({dist, i, j});
		}

		//cout << fixed << setprecision(4) << kruskal() << endl;
        cout << fixed << setprecision(4) << prim() << endl;
	}


    return 0;
}
