int partition(vi& a, int l, int r) {
    int p = a[l];
    int m = l;
    for (int k = l+1; k <= r; ++k) {
        if (a[k] < p) swap(a[k], a[++m]);
    }
    swap(a[l], a[m]);
    return m;
}
int rand_partition(vi& a, int l, int r) {
    int p = l + rand() % (r-l+1);
    swap(a[l], a[p]);
    return partition(a, l, r);
}
int qselect(vi& a, int l, int r, int k) {
    if (l == r) return a[l];
    int q = rand_partition(a, l, r);
    if (q+1 == k) return a[q];
    else if (q+1 > k) return qselect(a, l, q-1, k);
    else              return qselect(a, q+1, r, k);
}
