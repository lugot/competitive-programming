#include <bits/stdc++.h>

using namespace std;

int T;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	while (T--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int sx, sy, tx, ty;
		sx = min(x1, x2);
		sy = min(y1, y2);
		tx = max(x1, x2);
		ty = max(y1, y2);

		int gapx = abs(tx-sx);
		int gapy = abs(ty-sy);

		if (gapy < gapx) {
			if (gapx <= 2*(gapy-1)) {
				cout << gapx+gapy << endl;
				return 0;
			}
			int q = (gapx-gapy)/3;
			cout << gapx+gapy + 5*q + (5*q-(gapx-gapy)) << endl;
			return 0;
		}
		if (gapy > gapx) {
			if (gapy <= 2*(gapx-1)) {
				cout << gapx+gapy << endl;
				return 0;
			}
			int q = (gapy-gapx)/3;
			cout << gapx+gapy + 5*q + (5*q-(gapy-gapx)) << endl;
			return 0;
		}


	}


	return 0;
}
