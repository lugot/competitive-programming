#include <bits/stdc++.h>

using namespace std;
typedef long long L;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	vector<L> frac;
	
	int x;
	while(cin >> x) frac.push_back(x);

	L act_num=1L;
	for(int i=frac.size()-1; i>0; i--){
		frac[i-1] = act_num+frac[i]*frac[i-1];
		act_num = frac[i];
		
		if(act_num%frac[i-1] == 0){
			act_num = act_num / frac[i-1];
			frac[i-1] = 1;
		}
		if(frac[i-1]%act_num == 0){
			frac[i-1] = frac[i-1] / act_num;
			act_num = 1;
		}

	}

	cout << frac[0] << "/" << act_num << endl;

	return 0;
}
