class Solution
{
    public:
    int findRangeGcd(int l, int r, int st[], int n) 
    {
        return findGCDUtil(st, 0, n - 1, l, r, 0);
    }
    
    void updateValue(int index, int new_val, int *arr, int st[], int n) 
    {
        arr[index] = new_val;
        updateValueUtil(st, 0, n - 1, index, new_val, 0);
    }
    
    private:
    int findGCDUtil(int st[], int ss, int se, int qs, int qe, int si) 
    {
        if (qs <= ss && qe >= se)
            return st[si];
        if (se < qs || ss > qe)
            return 0;
        
        int mid = getMid(ss, se);
        int leftGCD = findGCDUtil(st, ss, mid, qs, qe, 2 * si + 1);
        int rightGCD = findGCDUtil(st, mid + 1, se, qs, qe, 2 * si + 2);
        
        return gcd(leftGCD, rightGCD);
    }

    void updateValueUtil(int st[], int ss, int se, int i, int new_val, int si) 
    {
        if (i < ss || i > se)
            return;
        
        if (ss == se) 
        {
            st[si] = new_val;
            return;
        }
        
        int mid = getMid(ss, se);
        
        if (i <= mid)
            updateValueUtil(st, ss, mid, i, new_val, 2 * si + 1);
        else
            updateValueUtil(st, mid + 1, se, i, new_val, 2 * si + 2);
        
        st[si] = gcd(st[2 * si + 1], st[2 * si + 2]);
    }
};
