class Solution
{
public:
    int countWays(int n)  
    {
        const int MOD = 1000000007;
        vector<int> table(n+1, 0);
        table[0] = 1;
        for (int i=1; i<n; i++) {
            for (int j=i; j<=n; j++) {
                table[j] = (table[j] + table[j-i]) % MOD;
            }
        }

        return table[n];  
    }  
};