class Solution
{
    public:
    int findCatalan(int n) 
    {
        const int MOD = 1e9+7;
        vector<long long> catalan(n + 1, 0);
        catalan[0] = 1;
        catalan[1] = 1;

        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                catalan[i] = (catalan[i] + (catalan[j] * catalan[i - 1 - j]) % MOD) % MOD;
            }
        }

        return (int)catalan[n];
    }
};