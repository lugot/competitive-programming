#include <bits/stdc++.h>

using namespace std;

struct box{
	double x1,y1,x2,y2;
	string size;
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	while(cin >> n){
		if (n==0) break;
			
		vector<box> boxes;

		double x1,y1,x2,y2;
		string size;
		while(n--){
			cin >> x1 >> y1 >> x2 >> y2 >> size;
			boxes.push_back({x1,y1,x2,y2,size});	
		}

		int m;
		cin >> m;
		
		double x,y;
		//string size;
		while(m--){
			cin >> x >> y >> size;		
			
			bool box_founded = false;
			for(struct box box: boxes){
				if (box.x1 <= x and x <= box.x2 and
					box.y1 <= y and y <= box.y2){
					
					cout << size << " ";
					if (size == box.size) cout << "correct" << endl;
					else cout << box.size << endl;
					
					box_founded=true;
					break;
				}
			}
			if (!box_founded) cout << size << " floor" << endl;
		}
		cout << endl;

	}

	return 0;
}
