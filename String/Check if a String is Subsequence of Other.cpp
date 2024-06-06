class Solution
{
public:
    // Function to check if a string is a subsequence of another string.
    bool isSubSequence(string A, string B)
    {
        int m = A.length();
        int n = B.length();
        
        int j = 0; // For index of A (or subsequence)
        
        // Traverse B and A, and compare current character of B with first unmatched char of A
        for (int i = 0; i < n && j < m; i++) {
            if (A[j] == B[i]) {
                j++;
            }
        }
        
        // If all characters of A were found in B
        return (j == m);
    }
};