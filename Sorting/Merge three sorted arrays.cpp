class Solution {
public:
    vector<int> mergeThree(vector<int>& A, vector<int>& B, vector<int>& C) {
        int n = A.size();
        int m = B.size();
        int p = C.size();
        
        vector<int> result;
        int i = 0, j = 0, k = 0;
        
        while (i < n && j < m && k < p) {
            if (A[i] <= B[j] && A[i] <= C[k]) {
                result.push_back(A[i]);
                i++;
            } else if (B[j] <= A[i] && B[j] <= C[k]) {
                result.push_back(B[j]);
                j++;
            } else {
                result.push_back(C[k]);
                k++;
            }
        }
        
        // If any array is exhausted
        while (i < n && j < m) {
            if (A[i] <= B[j]) {
                result.push_back(A[i]);
                i++;
            } else {
                result.push_back(B[j]);
                j++;
            }
        }
        
        while (j < m && k < p) {
            if (B[j] <= C[k]) {
                result.push_back(B[j]);
                j++;
            } else {
                result.push_back(C[k]);
                k++;
            }
        }
        
        while (i < n && k < p) {
            if (A[i] <= C[k]) {
                result.push_back(A[i]);
                i++;
            } else {
                result.push_back(C[k]);
                k++;
            }
        }
        
        // Add remaining elements
        while (i < n) {
            result.push_back(A[i]);
            i++;
        }
        
        while (j < m) {
            result.push_back(B[j]);
            j++;
        }
        
        while (k < p) {
            result.push_back(C[k]);
            k++;
        }
        
        return result;
    }
};