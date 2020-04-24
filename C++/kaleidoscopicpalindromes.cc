#include <bits/stdc++.h>

using namespace std;

bool is_palindrome(vector<int> v){
	for(int i=0; i<v.size()/2; i++)
		if (v[i] != v[v.size()-1-i]) return false;
	return true;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int a,b,k;
	cin >> a >> b >> k;

	int count=0;
	for(int n=a; n<=b; n++){
		//cout << "analizing " << n << " ..." << endl;

		//ma vaffanculo, è solo implementazione
		//questo è un trick per eliminarne molti.. se c'è zero alla fine in 
		// qualsiasi base è da scartare, ma non velocizza di molto
		// segno altri trick nei bookmarks di crome
		for(int i=2; i<=k; i++) if(n%k==0) continue;
		
		bool palindrome=true;
		int ncp=n;
		for(int i=2; i<=k; i++){
			//l'upper bound di questo for è abbassabile a n-2
			
			vector<int> v;
			while(n>0){
				v.push_back(n%i);
				n/=i;
			}

			n=ncp;

			if(!is_palindrome(v)){
				palindrome=false;
				break;
			}

		}
		if(palindrome) count++;
	
	}

	cout << count << endl;

	return 0;
}
