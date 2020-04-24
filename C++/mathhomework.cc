#include <bits/stdc++.h>
#include <vector>

using namespace std;

struct tri{
	int x,y,z;

	bool operator<(struct tri &b){
		if (x<b.x) return true;
		if (x>b.x) return false;

		if (y<b.y) return true;
		if (y>b.y) return false;

		if (z<b.z) return true;
		return false;
	}
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int b,d,c,l;
	cin >> b >> d >> c >> l;
	
	vector<tri> sol;
	int mi = l / min(min(b,d),c);

	for(int x=0; x<=mi; x++) for(int y=0; y<=mi; y++) for(int z=0; z<=mi; z++){
		if (x*b + y*d + z*c == l) sol.push_back({x,y,z});
	}

	if (sol.size() == 0) cout << "impossible\n";
	else{
		sort(sol.begin(), sol.end());
		for(auto tri: sol){
			cout << tri.x << " " << tri.y << " " << tri.z << endl;
		}
	}

	return 0;
}
