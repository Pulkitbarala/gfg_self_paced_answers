class Solution {
public:
    int minNumber(int arr[], int low, int high) {
        if (arr[low] <= arr[high]) {
            return arr[low];
        }
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (mid < high && arr[mid] > arr[mid + 1]) {
                return arr[mid + 1];
            }
            if (mid > low && arr[mid - 1] > arr[mid]) {
                return arr[mid];
            }
            if (arr[mid] > arr[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return arr[low];
    }
};