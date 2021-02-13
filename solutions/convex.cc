#include <bits/stdc++.h>

using namespace std;

struct point {
    int x,y;
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    int N;
    cin >> N;

    int max_int = 40000000;

    vector<point> lower;
    vector<point> upper;

    lower.push_back({0,0});
    lower.push_back({1,0});
    upper.push_back({max_int, max_int});

    N-=3;
    if (N != 0) {
        while (true) {
            
            point old = lower[lower.size()-1];


        }
    }


	return 0;
}
