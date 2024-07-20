class Solution {
public:
    vector<int> LargestFraction(int n, int d) {
        int maxP = 0, maxQ = 1;

        for (int q = d; q > 0 && q >= d - 10000; --q) {
            int p = (n * q - 1) / d;
            if (p >= 1 && __gcd(p, q) == 1) {
                if (1LL * maxP * q < 1LL * p * maxQ) {
                    maxP = p;
                    maxQ = q;
                }
            }
        }
        
        for (int q = d + 1; q <= 10000; ++q) {
            int p = (n * q - 1) / d;
            if (p >= 1 && __gcd(p, q) == 1) {
                if (1LL * maxP * q < 1LL * p * maxQ) {
                    maxP = p;
                    maxQ = q;
                }
            }
        }
        
        return {maxP, maxQ};
    }
};
//submit multiple times it is correct code. There is an issue in gfg platform.
