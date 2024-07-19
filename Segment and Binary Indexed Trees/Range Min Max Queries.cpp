void updateValueUtil(PII *st, int ss, int se, int i, int new_val, int si) {
    if (i < ss || i > se)
        return;
    
    if (ss == se) {
        st[si].first = st[si].second = new_val;
        return;
    }
    
    int mid = getMid(ss, se);
    
    if (i <= mid)
        updateValueUtil(st, ss, mid, i, new_val, 2 * si + 1);
    else
        updateValueUtil(st, mid + 1, se, i, new_val, 2 * si + 2);
    
    st[si].first = min(st[2 * si + 1].first, st[2 * si + 2].first);
    st[si].second = max(st[2 * si + 1].second, st[2 * si + 2].second);
}

void updateValue(int *arr, PII *st, int n, int index, int new_val) {
    if (index < 0 || index >= n)
        return;
    arr[index] = new_val;
    updateValueUtil(st, 0, n - 1, index, new_val, 0);
}
PII getMinMaxUtil(PII *st, int ss, int se, int qs, int qe, int si) {
    if (qs <= ss && qe >= se)
        return st[si];
    if (se < qs || ss > qe)
        return {INT_MAX, INT_MIN};
    int mid = getMid(ss, se);
    PII left = getMinMaxUtil(st, ss, mid, qs, qe, 2 * si + 1);
    PII right = getMinMaxUtil(st, mid + 1, se, qs, qe, 2 * si + 2);
    
    return {min(left.first, right.first), max(left.second, right.second)};
}

PII getMinMax(PII *st, int *arr, int n, int qs, int qe) {
    if (qs < 0 || qe >= n || qs > qe)
        return {INT_MAX, INT_MIN};
    return getMinMaxUtil(st, 0, n - 1, qs, qe, 0);
}