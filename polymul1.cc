#include<bits/stdc++.h>

using namespace std;

struct cd{
	double r,i;
	
	cd operator*(struct cd z){
		cd x;
		x.r = r*z.r - i*z.i;
		x.i = r*z.i + i*z.r;

		return x;
	}
	cd operator+(struct cd z){
		cd x;
		x.r = r + z.r;
		x.i = i + z.i;
		
		return x;
	}
	cd operator-(struct cd z){
		cd x;
		x.r = r - z.r;
		x.i = i - z.i;
		
		return x;
	}
};

//typedef complex<double> cd;
const double PI = 2.0*acos(0.0);

vector<cd> fast_fourier_transform(vector<cd> a){ 
	int n = a.size(); 
	if (n == 1) return vector<cd>(1, a[0]); 

	vector<cd> w(n);
	for(int i=0; i<n; i++){ 
		double alpha = 2 * M_PI * i / n; 
		w[i] = {cos(alpha), sin(alpha)}; 
	}

	vector<cd> A0(n / 2), A1(n / 2); 
	for (int i = 0; i < n / 2; i++) { 
		A0[i] = a[i * 2]; 
		A1[i] = a[i * 2 + 1]; 
	} 
	
	vector<cd> y0 = fast_fourier_transform(A0); 
	vector<cd> y1 = fast_fourier_transform(A1); 
	
	vector<cd> y(n); 

	for (int k = 0; k < n / 2; k++) { 
		y[k] = y0[k] + w[k] * y1[k]; 
		y[k + n / 2] = y0[k] - w[k] * y1[k]; 
	}

	return y; 
} 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	while(T--){	
		vector<cd> v1(256), v2(256);

		int n; double a;
		
		cin >> n;
		for(int i=0; i<n+1; i++){
			cin >> a;
			v1[i] = {a,0};
		}
		
		cin >> n;
		for(int i=0; i<n+1; i++){
			cin >> a;
			v2[i] = {a,0};
		}
		
		vector<cd> o1 = fast_fourier_transform(v1);
		vector<cd> o2 = fast_fourier_transform(v2);

		for(int i=0; i<o1.size(); i++){
			o1[i] = o1[i] * o2[i];
		}
		
		for(int i=1; i<o1.size()/2; i++){
			cd temp = o1[i];
			o1[i] = o1[o1.size()-i];
			o1[o1.size()-i]=temp;
		}
		
		for(struct cd &z: o1){
			if (fabs(z.r)<1e-9) z.r = round(z.r);
			if (fabs(z.i)<1e-9) z.i = round(z.i);
		}

		o1 = fast_fourier_transform(o1);
		
		vector<int> ans;
		for(auto &z: o1) ans.push_back( round(z.r/256.0) );

		int degree = ans.size()-1;
		while(ans[degree] == 0) degree--;
		
		cout << degree << endl;
		for(int i=0; i<=degree; i++) cout << ans[i] << " ";
		cout << endl;
	}

	return 0;
}
