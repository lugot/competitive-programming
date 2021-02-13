#include <bits/stdc++.h>

using namespace std;

int dp(string a, string b) { 
    int m = a.length(); 
    int n = b.length(); 
  
    int lookup[m+1][n+1] = {{0}}; 
  
    for (int i = 0; i <= n; ++i) lookup[0][i] = 0; 
    for (int i = 0; i <= m; ++i) lookup[i][0] = 1; 
  
    for(int i = 1; i <= m; i++){ 
        for(int j = 1; j <= n; j++){ 
            if (a[i-1] == b[j-1]) 
                lookup[i][j] = (lookup[i-1][j-1] +  
                                lookup[i-1][j]) % 10000; 
                  
            else
                lookup[i][j] = (lookup[i - 1][j]) % 10000; 
        } 
    } 
  
    return lookup[m][n]; 
} 

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	string u;
	getline(cin, u);
	T = stoi(u);

	for(int t=1; t<=T; t++){
		cout << "Case #" << t << ": ";

		string s;
		getline(cin, s);
		cout << fixed << setfill('0') << setw(4) << dp(s, "welcome to code jam") << endl;
	}

	return 0;
}
