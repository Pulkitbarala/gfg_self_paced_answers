class Solution
{
    public:
    bool findPartition(int a[], int n)
    {
        int total_sum = accumulate(a, a + n, 0);
        if (total_sum % 2 != 0) {
            return false;
        }
        
        int target = total_sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; ++i) {
            for (int j = target; j >= a[i]; --j) {
                dp[j] = dp[j] || dp[j - a[i]];
            }
        }
        
        return dp[target];
    }
};