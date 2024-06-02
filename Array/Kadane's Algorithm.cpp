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