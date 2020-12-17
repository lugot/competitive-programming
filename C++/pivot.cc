#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> nums(n);
	for(auto &x: nums) cin >> x;

	vector<int> maxx(n), minn(n);

	maxx[0] = nums[0];
	for(int i=1; i<n; i++)
		maxx[i] = max(maxx[i-1], nums[i]);

	minn[n-1] = nums[n-1];
	for(int i=n-2; i>=0; i--) 
		minn[i] = min(minn[i+1], nums[i]);

	int ans = 0;
	for(int i=1; i<n-1; i++){
		if (nums[i] >= maxx[i-1] and
			nums[i] <= minn[i+1]) ans++;
	}

	if (nums[0] <= minn[1]) ans++;
	if (nums[n-1] >= maxx[n-2]) ans++;

	cout << ans << endl;

	return 0;
}
