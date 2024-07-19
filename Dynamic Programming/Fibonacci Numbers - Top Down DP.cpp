class Solution
{
    public:
    long long findNthFibonacci(int number, long long int dp[])
    {
        if (number == 1 || number == 2)
            return 1;
        if (dp[number] != 0)
            return dp[number];
        dp[number] = findNthFibonacci(number - 1, dp) + findNthFibonacci(number - 2, dp);
        return dp[number];
    }
};