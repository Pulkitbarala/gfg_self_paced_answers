class Solution
{
    public:
    long long countWays(int n)
    {
        const int MOD = 1000000007;
        
        if (n == 0) return 1;
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 4;
        
        long long dp[n+1];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        
        for (int i = 4; i <= n; ++i) {
            dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % MOD;
        }
        
        return dp[n];
    }
};