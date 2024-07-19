class Solution
{
    public:
    long long findNthFibonacci(int number)
    {
        // Base cases
        if (number == 0) return 0;
        if (number == 1) return 1;
        long long fib[number + 1];
        fib[0] = 0;
        fib[1] = 1;
        for (int i = 2; i <= number; ++i)
        {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
        return fib[number];
    }
};
