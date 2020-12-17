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
 

struct edge {
    int w, u, v;
};

vector<edge> edgelist;
int E;
for (int i=0; i<E; i++) {
    scanf("%d %d %d", &u, &v, &w);
    // read the triple: (u, v, w)
    EdgeList.push_back(make_pair(w, ii(u, v))); 
}
sort(edgelist.begin(), edgelist.end());

int mst_cost = 0;
union_find uf(E);

for (int i=0; i<E; i++) {
     // for each edge, O(E)
    pair<int, ii> front = EdgeList[i];
    if (!UF.isSameSet(front.second.first, front.second.second)) { // check
        mst_cost += front.first;
         // add the weight of e to MST
        UF.unionSet(front.second.first, front.second.second);
         // link them
    }
}
// note: the runtime cost of UFDS is very light
// note: the number of disjoint sets must eventually be 1 for a valid MST
printf("MST cost = %d (Kruskal’s)\n", mst_cost);
