class Solution {
  public:
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        unordered_set<int> setA;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            setA.insert(a[i]);
        }
        for (int i = 0; i < m; ++i) {
            if (setA.find(b[i]) != setA.end()) {
                count++;
                setA.erase(b[i]);
            }
        }
        
        return count;
    }
};