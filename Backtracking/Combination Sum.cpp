class Solution {
  public:
    void findCombinations(vector<int> &A, int B, vector<int> &current, vector<vector<int>> &result, int start) {
        if (B == 0) {
            result.push_back(current);
            return;
        }
        
        for (int i = start; i < A.size(); i++) {
            if (A[i] > B) break;
            current.push_back(A[i]);
            findCombinations(A, B - A[i], current, result, i);
            current.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int> &A, int B) {
        sort(A.begin(), A.end());
        A.erase(unique(A.begin(), A.end()), A.end());
        vector<vector<int>> result;
        vector<int> current;
        findCombinations(A, B, current, result, 0);
        return result;
    }
};
