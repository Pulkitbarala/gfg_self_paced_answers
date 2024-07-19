class Solution {
  public:
    long long minimumNumberOfCoins(int coins[], int numberOfCoins, int value) {
        const int INF = INT_MAX;
        vector<int> dp(value + 1, INF);
        dp[0] = 0;
        
        for (int i = 0; i < numberOfCoins; ++i) {
            for (int j = coins[i]; j <= value; ++j) {
                if (dp[j - coins[i]] != INF) {
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }
        
        return (dp[value] == INF) ? -1 : dp[value];
    }
};
