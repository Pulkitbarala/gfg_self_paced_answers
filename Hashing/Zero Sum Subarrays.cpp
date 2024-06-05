class Solution {
public:
    // Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n) {
        unordered_map<long long int, int> cumSumFreq;
        long long int cumSum = 0;
        long long int count = 0;
        
        for (int i = 0; i < n; i++) {
            cumSum += arr[i];
            
            if (cumSum == 0) {
                count++;
            }
            
            if (cumSumFreq.find(cumSum) != cumSumFreq.end()) {
                count += cumSumFreq[cumSum];
            }
            
            cumSumFreq[cumSum]++;
        }
        
        return count;
    }
};