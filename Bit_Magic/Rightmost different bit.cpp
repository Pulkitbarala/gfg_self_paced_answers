class Solution
{
    public:
    int posOfRightMostDiffBit(int m, int n)
    {
        int res = 1;
        while(m > 0 || n > 0) {
            if((m % 2) != (n % 2)) {
                return res;
            }
            res++;
            m = m / 2;
            n = n / 2;
        }
        return -1;
    }
};