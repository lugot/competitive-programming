#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    int N, B;
    while(cin >> N >> B){
        if (N == -1) break;

        vector<int> cities(N);
        int sum = 0;

        int x;
        for (int i=0; i<N; i++){
            cin >> x;
            cities[i] = x;
            sum += x;
        }

        int assigned = 0;
        int ans = 0;
        sort(cities.begin(), cities.end());
        int last_ass;
        for(int i=0; i<N-1; i++){
            double mean = (sum+0.0) / (B-assigned);
            int act_assinged = (int) ceil((cities[i]+0.0) / mean);

            assigned += act_assinged;
            sum -= cities[i];

            //cout << cities[i] << " " << mean << " " << act_assinged << " " << assigned << endl;

            ans = max(ans, cities[i]/act_assinged);
            if (i == N-2) last_ass = B-assigned;
        }
        ans = max(ans, cities[N-1]/last_ass);

        cout << ans << endl;
    }

	return 0;
}
