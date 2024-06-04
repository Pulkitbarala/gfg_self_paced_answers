class Solution
{
    public:
    int maxStep(int A[], int N)
{
    int maxSteps = 0;
    int currSteps = 0;
    
    for (int i = 0; i < N - 1; i++) {
        if (A[i] < A[i + 1]) {
            currSteps++;
            maxSteps = max(maxSteps, currSteps);
        } else {
            currSteps = 0;
        }
    }
    
    return maxSteps;
}

};