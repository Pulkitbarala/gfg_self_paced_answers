ll getLCMUtil(ll *st, int ss, int se, int qs, int qe, int si) {
    if (qs <= ss && qe >= se)
        return st[si];
    if (se < qs || ss > qe)
        return 1;

    int mid = getMid(ss, se);
    return LCM(getLCMUtil(st, ss, mid, qs, qe, 2 * si + 1), getLCMUtil(st, mid + 1, se, qs, qe, 2 * si + 2));
}

ll getLCM(ll *st, int *arr, int n, int qs, int qe) {
    if (qs < 0 || qe > n - 1 || qs > qe)
        return -1;
    return getLCMUtil(st, 0, n - 1, qs, qe, 0);
}

void updateValueUtil(int *arr, ll *st, int ss, int se, int index, int new_val, int si) {
    if (index < ss || index > se)
        return;

    if (ss == se) {
        arr[index] = new_val;
        st[si] = new_val;
    } else {
        int mid = getMid(ss, se);
        updateValueUtil(arr, st, ss, mid, index, new_val, 2 * si + 1);
        updateValueUtil(arr, st, mid + 1, se, index, new_val, 2 * si + 2);
        st[si] = LCM(st[2 * si + 1], st[2 * si + 2]);
    }
}

void updateValue(int *arr, ll *st, int n, int index, int new_val) {
    if (index < 0 || index > n - 1)
        return;
    updateValueUtil(arr, st, 0, n - 1, index, new_val, 0);
}
