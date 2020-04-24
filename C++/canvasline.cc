#include <bits/stdc++.h>

using namespace std;

struct canv{
	long int l,r;
	int p;
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;

	vector<long> in(n), end(n);
	vector<int> peg(n);
	for(int i=0; i<n; i++) peg[i]=0;

	long l,r;
	for(int i=0; i<n; i++){
		cin >> l >> r;
		in[i]=l;
		end[i]=r;
	}

	int p;
	cin >> p;

	long x;
	vector<long int> fixed_pegs(p);
	for(int i=0; i<p; i++){
		cin >> x;
		fixed_pegs[i]=x;
		
		auto index =  lower_bound(in.begin(), in.end(), x);
		int position = distance(in.begin(), index);
		
		if (in[position]!=x) position--;
		
		peg[position]++;
		if (peg[position]>2){
			cout << "impossible\n";
			return 0;
		}

		if (position>0 and x==in[position] and end[position-1]==in[position]){
			peg[position-1]++;
			if (peg[position-1]>2){
				cout << "impossible\n";
				return 0;
			}
		}	
	}

	sort(fixed_pegs.begin(), fixed_pegs.end());
	
	vector<long int> final_pegs;
	for(int i=0; i<peg.size(); i++){
		
		if (peg[i]<2){
			if (i<peg.size()-1 and end[i]==in[i+1] and peg[i+1]<2){
				if (binary_search(fixed_pegs.begin(), fixed_pegs.end(), end[i]) == false and
					binary_search(final_pegs.begin(), final_pegs.end(), end[i]) == false ){
					
					final_pegs.push_back(end[i]);
					peg[i]++;
					peg[i+1]++;
				}
				else{
					long int next = in[i] + (end[i]-in[i])/2;
					if (binary_search(fixed_pegs.begin(), fixed_pegs.end(), next) or
						binary_search(final_pegs.begin(), final_pegs.end(), next)){
						next++;
					}
					final_pegs.push_back(next);
					peg[i]++;
				}
			}
			else{
				long int next = in[i] + (end[i]-in[i])/2;
				if (binary_search(fixed_pegs.begin(), fixed_pegs.end(), next) or
					binary_search(final_pegs.begin(), final_pegs.end(), next)){
					next++;
				}
				final_pegs.push_back(next);
				peg[i]++;
			}
			i--;
			sort(final_pegs.begin(), final_pegs.end());
		}
	}

	cout << final_pegs.size() << endl;
	for(auto &x: final_pegs) cout << x << " ";
	cout << endl;


	return 0;
}
