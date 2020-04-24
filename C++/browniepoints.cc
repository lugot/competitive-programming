#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while(true){
		int n;
		cin >> n;
		
		if (n==0) break;

		vector<pair<int,int>> p;
		
		int x, y;
		while(n--){
			cin >> x >> y;
			
			p.push_back({x,y});
		}

		int cx = p[p.size()/2].first;
		int cy = p[p.size()/2].second;
		
		int s=0, o=0;
		for (auto point: p){
			int x = point.first, y=point.second;

			if (x>cx and y>cy) s++;
			if (x<cx and y<cy) s++;
			if (x>cx and y<cy) o++;
			if (x<cx and y>cy) o++;
		}

		cout << s << " " << o << endl;
	}
	
	return 0;
}
