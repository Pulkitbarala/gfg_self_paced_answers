class Solution {   
public:
    vector<vector<int>> multiplyMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
        int n1 = A.size();
        int m1 = A[0].size();
        int n2 = B.size();
        int m2 = B[0].size();
        if (m1 != n2) {
            return {};
        }
        vector<vector<int>> result(n1, vector<int>(m2, 0));
        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < m2; ++j) {
                for (int k = 0; k < m1; ++k) {
                    result[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        
        return result;
    }
};