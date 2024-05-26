class Solution{
public:
    int countSetBits(int n) {
        if (n == 0)
            return 0;
        int x = largestPowerOf2(n);
        int bitsUpTo2PowX = x * (1 << (x - 1));
        int msbFrom2PowXToN = n - (1 << x) + 1;
        int remaining = n - (1 << x);
        
        return bitsUpTo2PowX + msbFrom2PowXToN + countSetBits(remaining);
    }
private:
    int largestPowerOf2(int n) {
        int x = 0;
        while ((1 << x) <= n)
            x++;
        return x - 1;
    }
};