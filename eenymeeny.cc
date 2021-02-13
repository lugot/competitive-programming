#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string r;
	getline(cin,r);
	int jump = count(r.begin(), r.end(), ' ');
	
	int n;
	cin >> n;

	vector<string> kids, team1, team2;
	string d;
	while(cin >> d) kids.push_back(d);

	int i=0, team_selector=0;
	while(!kids.empty()){
		i =  (i+jump) % kids.size();
		if (team_selector == 0)	team1.push_back(kids[i]); 
		else team2.push_back(kids[i]);
		
		kids.erase(kids.begin() +i);
		team_selector = (team_selector+1)%2;
	}

	printf("%d\n", team1.size());
	for(string x: team1) printf("%s\n", x.c_str());

	printf("%d\n", team2.size());
	for(string x: team2) printf("%s\n", x.c_str());


	return 0;
}
