class Solution {
public:
    int celebrity(vector<vector<int>>& M, int n) {
        int candidate = 0;
        
        for (int i = 1; i < n; i++) {
            if (M[candidate][i] == 1) {
                candidate = i;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (i != candidate && (M[candidate][i] == 1 || M[i][candidate] == 0)) {
                return -1;
            }
        }
        
        return candidate;
    }
};