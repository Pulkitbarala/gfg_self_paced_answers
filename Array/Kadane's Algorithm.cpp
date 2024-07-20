class Solution{
public:
    long long maxSubarraySum(int arr[], int n){
        long long max_so_far = arr[0];
        long long max_ending_here = arr[0];
        for (int i = 1; i < n; i++) {
            max_ending_here = max((long long)arr[i], max_ending_here + arr[i]);
            max_so_far = max(max_so_far, max_ending_here);
        }
        return max_so_far;
    }
};
-------------------------------------------------------------------------------------------------
class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(vector<int> &arr) {
        int n = arr.size();
        if (n == 0) return 0;

        long long current_max = arr[0];
        long long global_max = arr[0];

        for (int i = 1; i < n; ++i) {
            current_max = max((long long)arr[i], current_max + arr[i]);
            global_max = max(global_max, current_max);
        }

        return global_max;
    }
};
