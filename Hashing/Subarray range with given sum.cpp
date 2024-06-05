class Solution {
public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(int arr[], int n, int sum) {
        unordered_map<int, int> cumSumFreq;
        int cumSum = 0;
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            cumSum += arr[i];
            
            if (cumSum == sum) {
                count++;
            }
            
            if (cumSumFreq.find(cumSum - sum) != cumSumFreq.end()) {
                count += cumSumFreq[cumSum - sum];
            }
            
            cumSumFreq[cumSum]++;
        }
        
        return count;
    }
};