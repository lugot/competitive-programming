#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
int bsearch(vi a, int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (a[mid] == x) return mid;
        if (a[mid] > x)  return bsearch(a, l, mid - 1, x);
        return bsearch(a, mid + 1, r, x);
    }
    return -1;
}

binary_search(a.begin(), a.end(), x); // bool
upper_bound(a.begin(), a.end(), x); // first > x
lower_bound(a.begin(), a.end(), x); // first !< x
