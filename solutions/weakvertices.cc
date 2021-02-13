#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, a;
	while(cin >> n){
		if (n==-1) break;
		vector<int> ad[n];
		
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++){
				cin >> a;
				if (a==1){
					ad[i].push_back(j);
					//ad[j].push_back(i);
				}
			}


		for(int i=0; i<n; i++){
			int no_ver=0;
			for (int x: ad[i]) for (int y: ad[x]) 
				if (find(ad[i].begin(), ad[i].end(),y) != ad[i].end()) no_ver++; 
			
			if (no_ver==0) printf("%d ", i);
		}
		printf("\n");

	}


	return 0;
}
