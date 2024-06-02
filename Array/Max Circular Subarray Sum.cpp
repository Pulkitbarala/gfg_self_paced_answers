class Solution {
public:
    int kadane(int arr[], int num) {
        int max_so_far = arr[0], max_ending_here = arr[0];
        for (int i = 1; i < num; i++) {
            max_ending_here = max(arr[i], max_ending_here + arr[i]);
            max_so_far = max(max_so_far, max_ending_here);
        }
        return max_so_far;
    }
    int circularSubarraySum(int arr[], int num) {
        int max_kadane = kadane(arr, num);
        int total_sum = 0;
        for (int i = 0; i < num; i++) {
            total_sum += arr[i];
            arr[i] = -arr[i];
        }
        int max_wrap = total_sum + kadane(arr, num);
        if (max_wrap == 0) {
            return max_kadane;
        }
        return max(max_kadane, max_wrap);
    }
};