#include <bits/stdc++.h>

using namespace std;

void knapSack(int W, vector<int> wt, vector<int> val){

    int i, w; 
	int n = val.size();
    vector<vector<int>> K(n+1, vector<int>(W+1)); 
  
    for(i=0; i <= n; i++){ 
        for(w=0; w <= W; w++){ 

            if (i == 0 || w == 0)
                K[i][w] = 0; 
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], 
                          K[i - 1][w]); 
            else
                K[i][w] = K[i - 1][w]; 
        } 
    } 

	int res = K[n][W];
	vector<int> ans;

	w = W; 
    for (i = n; i > 0 && res > 0; i--) { 
          
        if (res == K[i - 1][w])  
            continue;         
        else { 
			ans.push_back(i-1);
  
            res = res - val[i - 1]; 
            w = w - wt[i - 1]; 
        } 
    } 

	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for(auto x: ans) cout << x << " ";
	cout << endl;
} 
  
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int C, n;
	while(cin >> C >> n){
		vector<int> val(n);
		vector<int> wt(n);

		for(int i=0; i<n; i++) cin >> val[i] >> wt[i];
		knapSack(C, wt, val);
	}

	return 0;
}
