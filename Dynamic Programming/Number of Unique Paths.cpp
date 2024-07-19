class Solution
{
    public:
 
    int NumberOfPath(int a, int b)
    {
        vector<vector<int>> dp(a, vector<int>(b, 0));
        
        for(int i = 0; i < a; i++)
            dp[i][0] = 1;
        for(int j = 0; j < b; j++)
            dp[0][j] = 1;
        
        for(int i = 1; i < a; i++) {
            for(int j = 1; j < b; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        return dp[a-1][b-1];
    }
};