void updateValueUtil(ll *st, int ss, int se, int index, int new_val, int si) {
    if (ss == se) {
        st[si] = new_val;
        return;
    }
    int mid = getMid(ss, se);
    if (index <= mid)
        updateValueUtil(st, ss, mid, index, new_val, 2 * si + 1);
    else
        updateValueUtil(st, mid + 1, se, index, new_val, 2 * si + 2);
    st[si] = st[2 * si + 1] + st[2 * si + 2];
}

void updateValue(int *arr, ll *st, int n, int index, int new_val) {
    arr[index] = new_val;
    updateValueUtil(st, 0, n - 1, index, new_val, 0);
}

ll getSumUtil(ll *st, int ss, int se, int l, int r, int si) {
    if (l <= ss && r >= se)
        return st[si];
    if (se < l || ss > r)
        return 0;
    int mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, l, r, 2 * si + 1) +
           getSumUtil(st, mid + 1, se, l, r, 2 * si + 2);
}

ll getsum(ll *st, int n, int l, int r) {
    return getSumUtil(st, 0, n - 1, l, r, 0);
}