#include <bits/stdc++.h>
#include <iterator>
#include <sstream>
#include <unordered_map>

using namespace std;

void printm(unordered_map<string,int> m){
	cout << "map print:\n";
	for(auto x: m){
		cout << x.first << " " << x.second << endl;
	}
}
void printm1(unordered_map<int, string> m){
	cout << "map print:\n";
	for(auto x: m){
		cout << x.first << " " << x.second << endl;
	}
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	unordered_map<string, int> def;
	unordered_map<int, string> value;

	string com;
	while(cin >> com){

		if (com == "clear"){
			def.clear();
			value.clear();
		}
		else if (com == "def"){
			string s;
			int x;
			cin >> s >> x;
			
			if (def.find(s) != def.end()) value.erase(def[s]);
			def[s]=x;
			value[x]=s;
		}
		else if (com == "calc"){
			string line;
			getline(cin, line);

			istringstream iss(line);
			vector<string> split(istream_iterator<string>{iss},
					istream_iterator<string>());

			int ans = 0;
			bool unk = false;
			if (def.count(split[0]) == 0 ) unk=true;
			else ans += def[split[0]];

			for(int i=0; i<split.size()-1 && unk==false; i++){
				if (split[i] == "+"){
					if (def.count(split[i+1]) == 0 ){
						unk=true;
						break;
					}
					
					ans += def[split[i+1]];
					i++;
				}
				if (split[i] == "-"){
					if (def.count(split[i+1]) == 0 ){
						unk=true;
						break;
					}
					
					ans -= def[split[i+1]];
					i++;
				}
			}
			cout << line.substr(1) + " "; 
			
			if (unk){
				cout << "unknown" << endl;
			} else {
				if (value.count(ans)>0) cout << value[ans] << endl;
				else cout << "unknown" << endl;
			}
		}
	}


	return 0;
}
