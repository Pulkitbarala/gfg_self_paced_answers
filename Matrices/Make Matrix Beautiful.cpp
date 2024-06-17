class Solution {
public:
    int findMinOpeartion(vector<vector<int> > matrix, int n) {
        int maxSum = 0;
        vector<int> rowSum(n, 0);
        vector<int> colSum(n, 0);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                rowSum[i] += matrix[i][j];
                colSum[j] += matrix[i][j];
            }
        }
        
        for (int i = 0; i < n; ++i) {
            maxSum = max(maxSum, rowSum[i]);
            maxSum = max(maxSum, colSum[i]);
        }
        
        int totalOperations = 0;
        
        for (int i = 0; i < n; ++i) {
            totalOperations += (maxSum - rowSum[i]);
        }
        
        return totalOperations;
    }
};
