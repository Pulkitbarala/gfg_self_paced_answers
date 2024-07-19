class Solution
{
    public:
    int FindMaxSum(int arr[], int n)
    {
        if (n == 0) return 0;
        if (n == 1) return arr[0];
        if (n == 2) return max(arr[0], arr[1]);
        
        int prev2 = arr[0];
        int prev1 = max(arr[0], arr[1]);
        for (int i = 2; i < n; ++i)
        {
            int curr = max(prev1, arr[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
};