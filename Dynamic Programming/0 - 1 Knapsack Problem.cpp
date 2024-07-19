class Solution
{
    public:
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int w = 1; w <= W; ++w) {
                if (wt[i - 1] <= w) {
                    dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - wt[i - 1]] + val[i - 1]);
                } else {
                    dp[i][w] = dp[i - 1][w];
                }
            }
        }
        
        return dp[n][W];
    }
};
