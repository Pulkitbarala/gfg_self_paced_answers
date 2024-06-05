class Solution{
    public:
    int doUnion(int a[], int n, int b[], int m)  {
        unordered_set<int> unionSet;
        for (int i = 0; i < n; ++i) {
            unionSet.insert(a[i]);
        }
        for (int i = 0; i < m; ++i) {
            unionSet.insert(b[i]);
        }
        return unionSet.size();
    }
};