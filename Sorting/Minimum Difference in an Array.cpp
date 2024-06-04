class Solution{
public:
    int MinimumDifference(int arr[], int n)
    {
        sort(arr, arr + n);
        int min_diff = INT_MAX;
        for (int i = 1; i < n; i++) {
            int diff = arr[i] - arr[i - 1];
            if (diff < min_diff) {
                min_diff = diff;
            }
        }
        return min_diff;
    }
};