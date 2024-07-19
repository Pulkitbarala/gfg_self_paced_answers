class Solution
{
    public:
    int eggDrop(int n, int k) 
    {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = 0;
            dp[i][1] = 1;
        }
        for (int j = 1; j <= k; ++j) {
            dp[1][j] = j;
        }
        for (int i = 2; i <= n; ++i) {
            for (int j = 2; j <= k; ++j) {
                dp[i][j] = INT_MAX;
                int low = 1, high = j;
                while (low <= high) {
                    int mid = low + (high - low) / 2;
                    int breakCase = dp[i - 1][mid - 1]; 
                    int notBreakCase = dp[i][j - mid];
                    dp[i][j] = min(dp[i][j], 1 + max(breakCase, notBreakCase));
                    if (breakCase > notBreakCase) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
            }
        }
        
        return dp[n][k];
    }
};