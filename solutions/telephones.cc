#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	while(cin >> N >> M){
		if (N == 0) break;

		int src, dst, start, duration;
		vector<pi> calls(N);
		for(auto &call: calls){
			cin >> src >> dst >> start >> duration;
			call.first = start;
			call.second = start+duration-1;
		}
		//cout << endl;
		//for(auto i: calls)
			//cout << i.first << " " << i.second << endl;
		//cout << endl;
		
		vector<pi> intervals(M);
		for(auto &intv: intervals){
			cin >> start >> duration;
			intv.first = start;
			intv.second = start+duration-1;
		}

		//for(auto i: intervals)
			//cout << i.first << " " << i.second << endl;
		//cout << endl;

		vector<int> ans(M, 0);
		for(pi call: calls){
			int a = call.first, 
				b = call.second;

			for(int j=0; j<M; j++){
				int c = intervals[j].first,
					d = intervals[j].second;

				if (a >= c and a <= d) ans[j]++;
				else if (b >= c and b <= d) ans[j]++;
				else if (a <= c and b >= d) ans[j]++;
				//if (a <= c && b >= c) ans[j]++;
				//if (a >= c && b <= d) ans[j]++;
				//if (a < c && b > d) ans[j]++;
			}
		}

		for(auto a: ans) cout << a << endl;
	}

	return 0;
}
