#include <bits/stdc++.h>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> adjlist;

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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n;
    cin >> n;
    
    map<string, int> direct;
    map<int, string> inverse;

    adj = adjlist(5000);

    string s1, s2;
    int nodeidx = 0;
    while (n--) {
        cin >> s1 >> s2;

        if (direct.count(s1) == 0) {
            direct[s1] = nodeidx;
            inverse[nodeidx++] = s1;
        }
        if (direct.count(s2) == 0) {
            direct[s2] = nodeidx;
            inverse[nodeidx++] = s2;
        }

        int a = direct[s1];
        int b = direct[s2];

        adj[a].push_back(b);
    }

    string s;
    while (cin >> s) {
        visited = vi(5000, 0);
        recstack = vi(5000, 0);

        cout << s << " ";
        if (dfs(direct[s])) cout << "safe" << endl;
        else                cout << "trapped" << endl;
    }

	return 0;
}
