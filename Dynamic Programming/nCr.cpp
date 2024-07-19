class Solution
{
    public:
    int nCrModp(int n, int r) 
    { 
        const int MOD = 1e9 + 7;

        if (r > n) return 0;
        vector<vector<int>> dp(n + 1, vector<int>(r + 1, 0));
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= min(i, r); ++j) {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % MOD;
            }
        }
        
        return dp[n][r];
    }
};