class Solution {
public:
    vector<int> solve(int N, vector<int>& a) {
        vector<int> dp(N);
        dp[0] = a[0];
        dp[1] = max(a[0], a[1]);
        for (int i = 2; i < N; ++i) {
            dp[i] = max(a[i] + dp[i - 2], dp[i - 1]);
        }
        return dp;
    }
};
