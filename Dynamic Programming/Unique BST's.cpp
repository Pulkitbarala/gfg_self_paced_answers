class Solution
{
    public:
    int numTrees(int N) 
    {
        const int MOD = 1e9 + 7;
        vector<int> dp(N + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= N; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] = (dp[i] + (1LL * dp[j] * dp[i - 1 - j]) % MOD) % MOD;
            }
        }
        
        return dp[N];
    }
};