class Solution
{
    public:
    long long sumSubstrings(string s) {
        const int MOD = 1e9 + 7;
        long long totalSum = 0;
        long long currentSum = 0;
        long long multiplier = 1;

        for (int i = 0; i < s.size(); ++i) {
            int digit = s[i] - '0'; 
            currentSum = (currentSum * 10 + (i + 1) * digit) % MOD;
            totalSum = (totalSum + currentSum) % MOD;
        }

        return totalSum;
    }
};
