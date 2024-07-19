class Solution
{
    public:
    int maxSumSubarray(int A[], int n)
    {
        if (n == 1) return A[0];
        vector<int> maxEndingHere(n, 0);
        vector<int> maxStartingHere(n, 0);
        maxEndingHere[0] = A[0];
        for (int i = 1; i < n; ++i) {
            maxEndingHere[i] = max(A[i], maxEndingHere[i-1] + A[i]);
        }
        maxStartingHere[n-1] = A[n-1];
        for (int i = n-2; i >= 0; --i) {
            maxStartingHere[i] = max(A[i], maxStartingHere[i+1] + A[i]);
        }
        int maxSumNoRemove = *max_element(maxEndingHere.begin(), maxEndingHere.end());
        int maxSumWithRemove = INT_MIN;
        for (int i = 1; i < n-1; ++i) {
            maxSumWithRemove = max(maxSumWithRemove, maxEndingHere[i-1] + maxStartingHere[i+1]);
        }
        return max(maxSumNoRemove, maxSumWithRemove);
    }
};