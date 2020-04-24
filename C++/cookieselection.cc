#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> v;
	int c;
	while( scanf("%d\n", &c) ){
		printf("%d\n", c);
		if (c!=35) v.push_back(c);
		else {
			sort(v.begin(), v.end());
			if (v.size() %2 != 0){
				printf("%d\n", v[ (v.size()+1) /2 ]);
				v.erase(v.begin() + (v.size()+1)/2 -1);
			} else {
				printf("%d\n", v[ v.size()/2+1 ]);
				v.erase(v.begin() + v.size()/2);
			}
		}
	}


	return 0;
}
