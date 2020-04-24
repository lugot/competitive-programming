#include <bits/stdc++.h>

using namespace std;

char m[17][17];

bool fsort(const string &a, const string &b){
	string lowera = string(a.length(), '_');
	transform(a.begin(), a.end(), lowera.begin(), 
			[](unsigned char c){ return tolower(c);});
	
	string lowerb = string(a.length(), '_');
	transform(b.begin(), b.end(), lowerb.begin(), 
			[](unsigned char c){ return tolower(c);});
	
	return lowera.compare(lowerb) < 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int r,c;
	while(true){
		cin >> r >> c;
		if (r==0 and c==0) return 0;

		string k; 
		for(int i=0; i<r; i++){
			cin >> k;
			for(int j=0; j<c; j++){
				m[i][j]=k[j];
			}
		}

		vector<string> v(c);
		for(int i=0; i<c; i++) v[i] = string(r,'_');

		for(int i=0; i<r; i++) for(int j=0; j<c; j++){
			v[j][i]=m[i][j];
		}

		stable_sort(v.begin(), v.end(), fsort);
	
		for(int i=0; i<c; i++){
			for(int j=0; j<r; j++){
				m[j][i] = v[i][j];
			}
		}

		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
				cout << m[i][j];
			}
			cout << endl;
		}
		cout << endl << endl;
	}

	return 0;
}
