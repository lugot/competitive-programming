#include <bits/stdc++.h>

using namespace std;

struct PT{
	int x,y;
};

double trap(PT a, PT b){
	return (0.5*(b.x - a.x)*(b.y + a.y));
}

double area(vector<PT> &vin){
	int n = vin.size();
	double ret = 0.0;
	for(int i=0; i<n; i++) ret+= trap(vin[i], vin[(i+1)%n]);
	return fabs(ret);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m,x,y;
	double area=0.0;
	cin >> n;
	while(n--){
		cin >> m;
		
		vector<PT> poly;
		while(m--){
			cin >> x >> y;
			poly.push_back({x,y});
		}
		//poly.push_back({poly[0].x, poly[0].y});
		
		
		area=0.0;
		for(int i=0; i<poly.size(); i++){
			area+= poly[i].x*poly[i+1].y -	
				poly[i+1].x*poly[i].y;
		}
		
		cout << fabs(0.5*area) << endl;
	}


	return 0;
}
