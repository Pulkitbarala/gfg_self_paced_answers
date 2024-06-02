class Solution {
public:
    int minAdjDiff(int arr[], int n) {
        int min_diff = INT_MAX; 
        for (int i = 0; i < n; i++) {
            int next_index = (i + 1) % n;
            int diff = abs(arr[i] - arr[next_index]);
            min_diff = min(min_diff, diff);
        }
        return min_diff;
    }
};