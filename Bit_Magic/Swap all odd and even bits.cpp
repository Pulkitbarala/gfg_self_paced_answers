class Solution
{
    public:
    unsigned int swapBits(unsigned int n)
    {
        unsigned int even_bits = n & 0xAAAAAAAA;
        unsigned int odd_bits = n & 0x55555555;
        even_bits >>= 1;
        odd_bits <<= 1;
        return (even_bits | odd_bits);
    }
};