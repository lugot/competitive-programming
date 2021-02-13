#include <bits/stdc++.h>

using namespace std;

bool fsort(const pair<int,int> &a, const pair<int, int> &b){
	if (a.first == b.first) return a.second<b.second;
	return a.first>b.first;
}

struct TRI{
	int a,b,c;
	
	bool operator<(const TRI &t) const{
		if (b==t.b) return c < t.c;
		return b > t.b;
	}
};


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N,C;
	cin >> N >> C;
	
	vector<TRI> v;
	
	int x,i=0;
	while(N--){
		cin >> x;
		
		int i=0;
		for(i=0; i<v.size(); i++)
			if (v[i].a == x){
				v[i].b++;
				break;
			}
		if (i==v.size()) v.push_back({x,1,i++});
	}
	
	sort(v.begin(), v.end());
	for(auto &x: v){
		for(int i=0; i<x.b; i++) cout << x.a << " ";
	}
	cout << endl;
	

	return 0;
}
