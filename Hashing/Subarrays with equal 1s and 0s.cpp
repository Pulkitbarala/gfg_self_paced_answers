class Solution{
public:
    // Function to count subarrays with equal number of 0s and 1s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n) {
        unordered_map<int, int> cumSumFreq;
        int cumSum = 0;
        long long int count = 0;
        
        for (int i = 0; i < n; i++) {
            cumSum += (arr[i] == 1) ? 1 : -1;
            
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