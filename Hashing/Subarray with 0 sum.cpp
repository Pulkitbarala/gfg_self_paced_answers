class Solution {
public:
    bool subArrayExists(int arr[], int n) {
        unordered_set<int> cumSumSet;
        
        int cumSum = 0;
        for (int i = 0; i < n; i++) {
            cumSum += arr[i];
            
            if (cumSum == 0 || cumSumSet.find(cumSum) != cumSumSet.end()) {
                return true;
            }
            
            cumSumSet.insert(cumSum);
        }
        
        return false;
    }
};
