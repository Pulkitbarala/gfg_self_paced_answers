class Solution{
    public:
        //Complete this function
    double termOfGP(int A,int B,int N)
    {
        double commonRatio = (double) B / (double) A;
        double nthTerm = A * pow(commonRatio, N-1);
        return nthTerm;
    }
};