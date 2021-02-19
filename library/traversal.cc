#include<bits/stdc++.h>
using namespace std;

typedef double wtype; // change weighttype

typedef pair<int, wtype> iw;
typedef pair<wtype, int> wi;
typedef vector<iw> viw;
typedef vector<int> vi;
typedef vector<viw> adjlist;

int n, m;  
adjlist alist;
vi visited;
vi parent;
vi restack;
vi dist;

// DFS
bool dfs_cycledetection(int x) { 
    if (!visited[x]) { 

        visited[x] = 1; 
        restack[x] = 1; 
  
        for(auto [u, w]: alist[x]) { 
            if (!visited[u] && dfs_cycledetection(u)) return true; 
            else if (restack[u]) return true; 
        } 
  
    } 
    restack[x] = 0;
    return false; 
} 
void dfs(int x) {
    visited[x] = 1; 
  
    for(auto [u, w]: alist[x]) { 
        parent[u] = x;
        if (!visited[u]) dfs(u);
    }
}

// TOPOSORTING
bool cycle;
vi ts;

bool toposort_cycledetection(int x) {
    if (cycle) return true;
    visited[x] = 1;

    for (auto [u, w] : alist[x]) {
        if (visited[u] == 0) toposort_cycledetection(u);
        if (visited[u] == 1) {
            cycle = true;
            return true;
        }
    }
    ts.push_back(x);
    visited[x] = 2;
    return false;
    /*
     *in main:
     *reverse(ts.begin(), ts.end());
     */
}
void toposort(int x) {
    visited[x] = 1;

    for (auto [u, w] : alist[x]) {
        if (visited[u]) continue;

        toposort(u);
    }
    ts.push_back(x);
    /*
     *in main:
     *reverse(ts.begin(), ts.end());
     */
}
void toposorting_khan() {

    vi deg(n, 0); 
  
    for (int u=0; u<n; u++) deg[u] = alist[u].size();
    queue<int> q; 

    for (int u=0; u<n; u++) {
        if (deg[u] > 0) continue;

        visited[u] = 1;
        ts.push_back(u);
        q.push(u);
    }
    
    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (auto [v, w]: alist[u]) {
            if (visited[v]) continue;

            deg[v]--;
            if (deg[v] > 0) continue;

            visited[u] = 1;
            ts.push_back(v);
            q.push(v);
        }
    }
} 

// BFS
void bfs(int x) {
    visited[x] = 1;
    dist[x] = 0;
    parent[x] = x;

    queue<int> q;
    q.push(x);

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (auto [v, w]: alist[u]) {
            if (visited[v]) continue;

            visited[v] = 1;
            dist[v] = dist[u] + 1;
            parent[v] = u;

            q.push(v);
        }
    }
}

int main() {

    return 0;
}
