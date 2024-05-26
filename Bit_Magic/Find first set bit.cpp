class Solution
{
    public:
    unsigned int getFirstSetBit(int n)
    {
        if (n == 0) {
            return 0;
        } else {
            return (int)(log2(n & -n) + 1);
        }
    }
};