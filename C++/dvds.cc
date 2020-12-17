#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    int k;
    cin >> k;

    while(k--){
        int n;
        cin >> n;

        vector<int> dvds(n);
        for(auto &x: dvds) cin >> x;

        int ans2 = 0;
        int index = 1;
        for(auto x: dvds){
            if (x != index) ans2++;
            else index++;
        }

        cout << ans2 << endl;
    }

	return 0;
}
