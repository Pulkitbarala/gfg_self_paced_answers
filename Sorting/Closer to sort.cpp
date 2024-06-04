class Solution {
public:
    int closer(int arr[], int n, int x) {
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == x) 
                return mid;
            if (mid > low && arr[mid - 1] == x)
                return mid - 1;
            if (mid < high && arr[mid + 1] == x)
                return mid + 1;

            if (arr[mid] > x)
                high = mid - 2;
            else
                low = mid + 2;
        }

        return -1; // Element not found
    }
};