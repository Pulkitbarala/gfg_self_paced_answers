class Solution
{
    public:
    int lcs(string X, string Y, int m, int n)
    {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (X[i-1] == Y[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[m][n];
    }
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        int lcsLength = lcs(X, Y, m, n);
        return m + n - lcsLength;
    }
};