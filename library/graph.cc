#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<int, int> ii;

/*
 *DFS with CYCLE DETECTION
 */
adjlist adj;
vi visited;
vi recstack;

bool dfs(int x)  { 
    if(!visited[x]) { 

        visited[x] = 1; 
        recstack[x] = 1; 
  
        for(int u: adj[x]) { 
            if (!visited[u] && dfs(u)) return true; 
            else if (recstack[u]) return true; 
        } 
  
    } 
    recstack[x] = 0;
    return false; 
} 


/*
 *TOPOSORTING
 */
vector<int> visited; 
vector<int> ts;

void toposort(int u, vector<vector<int>>& adj) {
    visited[u] = 1;
    for (auto &v : adj[u]) if (!visited[v]) toposort(v, adj);
    ts.push_back(u);
}
/*in main:
 *    visited = vector<int>(n, 0);
 *    toposort(s, adj);
 *    reverse(ts.begin(), ts.end());
 */

/*
 *aggiungi khan
 */



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);


	return 0;
}
