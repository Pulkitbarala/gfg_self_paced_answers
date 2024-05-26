class Solution
{
    public:
    int maxAND(int arr[], int N)
    {
        int res = 0, count;
        for (int bit = 31; bit >= 0; bit--)
        {
            count = checkBit(res | (1 << bit), arr, N);
            if (count >= 2)
                res |= (1 << bit);
        }

        return res;
    }

    int checkBit(int pattern, int arr[], int n)
    {
        int count = 0;
        for (int i = 0; i < n; i++)
            if ((pattern & arr[i]) == pattern)
                count++;
        return count;
    }
};