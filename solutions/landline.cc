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

typedef pair<int, wtype> iw;
typedef pair<wtype, int> wi;
typedef vector<iw> viw;
typedef vector<int> vi;
typedef vector<viw> adjlist;

int n, m, p;
edgelist elist;
adjlist alist;
vi insicure;
bool skipcheck = false;

// KRUSKAL, O(mlogm)
union_find uf(0);
wtype kruskal() {
    wtype mst_cost = 0;

    sort(elist.begin(), elist.end());
    uf = union_find(n);

    for (auto [w, u, v]: elist) {

        if (!skipcheck and (insicure[u] or insicure[v])) continue;

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

    int start = 0;
    while (insicure[start]) start++;
    process(start);

    while (!pq.empty() and num_taken < n-p) {
        auto [w, u] = pq.top(); pq.pop();
        if (insicure[u]) continue;
        if (taken[u]) continue;

        mst_cost += w;
        process(u);

        num_taken++;
    }

    return mst_cost;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m >> p;

    if (m == 0) {
        cout << "0" << endl;
        return 0;
    }
    if (n == p) skipcheck = true;

    insicure = vi(n, 0);
    for (int i=0; i<p; i++) {
        int x;
        cin >> x;

        insicure[x-1] = 1;
    }


    elist = edgelist(m);
    alist = adjlist(n);
    for (auto& [l, x, y]: elist) {
        cin >> x >> y >> l;
        x--; y--;

        alist[x].push_back({y, l});
        alist[y].push_back({x, l});
    }

    wtype kcost = kruskal();
    if (skipcheck) {
        cout << kcost << endl;
        return 0;
    }

    for (int u=0; u<n; u++) {
        if (!insicure[u]) continue;

        wtype cost = 1e9;
        for (auto [v, w]: alist[u]) {
            if (!insicure[v]) cost = min(cost, w);
        }

        if (cost == 1e9) {
            cout << "impossible" << endl;
            return 0;
        }

        kcost += cost;
    }

    if (uf.num_sets > 1+p) {
        cout << "impossible" << endl;
        return 0;
    }

    cout << kcost << endl;

    return 0;
}
