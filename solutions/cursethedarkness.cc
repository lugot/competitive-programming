#include <bits/stdc++.h>

using namespace std;

double dst(double X, double Y, double a, double b){
	return sqrt( (X-a)*(X-a) + (Y-b)*(Y-b) );
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int m;
	cin >> m;

	while(m--){
		double X,Y;
		cin >> X >> Y;
		
		int n;
		cin >> n;
	
		string ans = "curse the darkness";
		
		double a,b;
		while(n--){
			cin >> a >> b;
			if (dst(X,Y,a,b) <= 8.0) ans = "light a candle";
		}

		cout << ans << endl;
	}

	return 0;
}
