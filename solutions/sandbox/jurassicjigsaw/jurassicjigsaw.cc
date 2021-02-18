#include<bits/stdc++.h>

using namespace std;

typedef int wtype; // change weighttype

typedef vector<pair<int, int>> prim_tree;
typedef tuple<wtype, int, int> wii;

typedef pair<int, wtype> iw;
typedef pair<wtype, int> wi;
typedef vector<iw> viw;
typedef vector<int> vi;
typedef vector<viw> adjlist;

int n, m;  
adjlist alist;

// PRIM, O(mlogm)
vi taken;
priority_queue<wii, vector<wii>, greater<wii>> pq;
prim_tree ptree;

void process(int x) {
    taken[x] = 1;
    for (auto [u, w]: alist[x]) {
        if (taken[u]) continue; 
        pq.push({w, u, x});
    } 
}
wtype prim() { // O(mlogm)
    wtype mst_cost = 0;

    taken = vi(n, 0);
    int num_taken = 0;

    process(0);

    while (!pq.empty() and num_taken < n) { 
        auto [w, u, x] = pq.top(); pq.pop();

        if (taken[u]) continue;

        ptree.push_back({x, u});
        mst_cost += w;
        process(u);

        num_taken++;
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

    alist = adjlist(n);
	for (int i=0; i<n; i++) for (int j=i+1; j<n; j++) {
        int dist = diff(samples[i], samples[j]);

        alist[i].push_back({j, dist});
        alist[j].push_back({i, dist});
	}

	cout << prim() << endl;
	for (auto [u, v]: ptree) cout << u << " " << v << endl;


    return 0;
}
