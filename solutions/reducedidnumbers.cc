#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int G;
	cin >> G;

	vector<int> stu(G);
	for(auto &x: stu) cin >> x;

	// wtf O(1M*300) passed no way
	for(int i=G; i<=1000000; i++){
		map<int, int> mods;

		bool distinct = true;
		for(auto id: stu){
			int mod = id%i;
			
			if (mods[mod] != 0){
				distinct = false;
				break;
			}

			mods[mod] = 1;
		}

		if (distinct){
			cout << i << endl;
			break;
		}
	}

	return 0;
}
