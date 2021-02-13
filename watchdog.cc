#include <bits/stdc++.h>

using namespace std;

struct PT{
	int x,y;
};
double dist(PT &a, PT &b){
	return sqrt((a.x-b.x)*(a.x-b.x) +(a.y-b.y)*(a.y-b.y));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	while(N--){
		
		int S,H;
		cin >> S >> H;
		vector<PT> points;


		int X,Y;
		while(H--){
			cin >> X >> Y;
			points.push_back({X,Y});
		}
			
		int i=0, j=0;
		for(; i<=S; i++){

			bool double_break=false;

			for(j=1; j<=S; j++){
				
				bool need_to_break=false;
				int h=0;
				for(; h<points.size(); h++){
					PT p = points[h];
					if (p.x==i and p.y==j){
						need_to_break=true;
						break;
					}

					PT act = {i,j};
					double x = p.x+0.0,
						   y = p.y+0.0,
						   dst = dist(act,p);

					if ( i-dst < 0.0 or j-dst < 0.0 or 
							i+dst > S or j+dst > S){
						need_to_break=true;
						break;

					}
				}

				if (h==points.size()){
					cout << i << " " << j << endl;
					double_break=true;
					break;
				}

			}

			if (double_break) break;
		}
		
		if (i==S+1 and j==S+1) cout << "poodle\n";

	}

	return 0;
}
