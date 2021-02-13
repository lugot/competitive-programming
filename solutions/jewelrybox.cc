// Ternary search
#include <bits/stdc++.h>

using namespace std;

double X,Y;

double vol(double h){
	return h*(X-2*h)*(Y-2*h);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;

	while(T--){
		//double X,Y;
		cin >> X >> Y;

		double hi = 1.0/2*max(X,Y), low = 0.0;
		double m1 = low + (hi-low)/3.0;
		double m2 = low + (hi-low)*2.0/3.0;
		
		while(fabs(m1-m2)>1e-9){
			m1 = low + (hi-low)/3;
			m2 = low + (hi-low)*2/3;
			
			double fm1 = vol(m1), fm2 = vol(m2);

			if (fm1 > fm2) hi = m2;
			else low = m1;
		}

		cout << fixed << setprecision(6);
		cout << m1*(X-2*m1)*(Y-2*m1) << endl; 
	}

	return 0;
}
