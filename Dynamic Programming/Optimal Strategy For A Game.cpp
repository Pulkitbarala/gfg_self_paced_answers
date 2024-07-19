class Solution{
public:
    long long maximumAmount(int n, int arr[]) {
        vector<vector<long long>> dp(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = arr[i];
        }
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                long long pickLeft = arr[i] + min((i + 2 < n ? dp[i + 2][j] : 0), (i + 1 < n && j - 1 >= 0 ? dp[i + 1][j - 1] : 0));
                long long pickRight = arr[j] + min((i + 1 < n && j - 1 >= 0 ? dp[i + 1][j - 1] : 0), (j - 2 >= 0 ? dp[i][j - 2] : 0));
                dp[i][j] = max(pickLeft, pickRight);
            }
        }
        return dp[0][n-1];
    }
};