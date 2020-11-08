#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for(int t=1; t<=T; t++){
		int N;
		cin >> N;

		vector<int> nums(N);
		for(int &x: nums) cin >> x;

		vector<pair<int, int>> ssets;
		for (int b = 0; b < (1<<N); b++) {

			int sum = 0;
			for (int i = 0; i < N; i++)
				if (b&(1<<i)) sum += nums[i];

			ssets.push_back({b, sum});
		}

		sort(ssets.begin(), ssets.end(),
				[](pair<int, int> a, pair<int, int> b)
				{ return a.second < b.second;});

		cout << "Case #" << t << ":" << endl;
		bool found = false;
		for(int i=0; i<ssets.size()-1; i++){
			if (ssets[i].second == ssets[i+1].second){
				for (int j = 0; j < N; j++)
					if (ssets[i].first&(1<<j)) cout << nums[j] << " ";
				cout << endl;
				for (int j = 0; j < N; j++)
					if (ssets[i+1].first&(1<<j)) cout << nums[j] << " ";
				cout << endl;

				found = true;
				break;
			}
		}

		if (!found) cout << "Impossible" << endl;



	}


	return 0;
}
