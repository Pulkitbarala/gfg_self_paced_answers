class Solution{
    public:
        long long sumUnderModulo(long long a,long long b)
    {
       int M=1000000007;
    a = a%M;
    b = b%M;
    return (a+b)%M; // code here
    }
};