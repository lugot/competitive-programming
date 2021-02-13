#include <bits/stdc++.h>

using namespace std;

void compute(vector<string> m){
	int h = m.size(), w = m[0].length();
	
	vector<int> p, sum(h,0);
	for(string s: m){
		
		int counter = 0;
		for(char c: s) if (c=='*') counter++;

		p.push_back(counter);
	}
	
	sum[0]=p[0];
	for(int i=1; i<h; i++) sum[i] = sum[i-1] + p[i];
	
	for(int i=0; i<h; i++){
		for(int j=0; j<w-sum[i]; j++) cout << '.';
		for(int j=0; j<p[i]; j++) cout << '*';
		for(int j=0; j<sum[i]-p[i]; j++) cout << '.';
		cout << endl;
	}


}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	vector<string> m;
	while(getline(cin,s)){
			
		if (s==""){
			compute(m);
			cout << endl;
			m.clear();
		}else{
			m.push_back(s);
		}
	}
	compute(m);



	return 0;
}
