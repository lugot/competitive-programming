#include <bits/stdc++.h>

using namespace std;

struct prize{
	int k,c;
	vector<int> sticker;
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;

	while(T--){
		int n,m;
		cin >> n >> m;

		vector<prize> prizes;
		for(int i=0; i<n; i++){
			int k;
			cin >> k;

			vector<int> temp(k);
			int x;
			for(int j=0; j<k; j++){
				cin >> x;
				temp[j]=x;
			}

			int c;
			cin >> c;

			prizes.push_back({k,c,temp});
		}

		vector<int> stickers;
		int x;
		for(int i=0; i<m; i++){
			cin >> x;
			stickers.push_back(x);
		}
		



		int ans=0;
		for(auto prize: prizes){
			int mink = stickers[prize.sticker[0]-1];
			for(auto sticker: prize.sticker) mink = min(mink, stickers[sticker-1]);
			
			ans += prize.c*mink;
		}

		cout << ans << endl;

	}

	return 0;
}
