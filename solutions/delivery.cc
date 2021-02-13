#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N,K;
	cin >> N >> K;

	vector<pi> pos, neg;
	int x, t;
	while(N--){
		cin >> x >> t;
		if (x > 0) pos.push_back({x, t});
		else   	   neg.push_back({-x, t});
	}

	sort(pos.begin(), pos.end(), greater<pi>());
	sort(neg.begin(), neg.end(), greater<pi>());

	int ans = 0;
	for(int i=0; i<pos.size(); i++){
		int num_travels = pos[i].second/K;
		if (pos[i].second%K != 0) num_travels++;
		ans += 2*pos[i].first*num_travels;
		
		int remain = K - pos[i].second%K;
		if (remain == K) remain = 0;
		int j = i;
		while(remain > 0 and j != pos.size()-1){
			int old_storage = pos[j+1].second;
			pos[j+1].second = max(0, pos[j+1].second - remain);
			remain -= old_storage;
			j++;
		}
		//if (i != pos.size()-1) pos[i+1].second = max(0, pos[i+1].second - remain);
	}

	for(int i=0; i<neg.size(); i++){
		int num_travels = neg[i].second/K;
		if (neg[i].second%K != 0) num_travels++;
		ans += 2*neg[i].first*num_travels;

		int remain = K - neg[i].second%K;
		if (remain == K) remain = 0;
		int j = i;
		while(remain > 0 and j != neg.size()-1){
			int old_storage = neg[j+1].second;
			neg[j+1].second = max(0, neg[j+1].second - remain);
			remain -= old_storage;
			j++;
		}
		//if (i != neg.size()-1) neg[i+1].second = max(0, neg[i+1].second - remain);
	}

	cout << ans << endl;


	return 0;
}
