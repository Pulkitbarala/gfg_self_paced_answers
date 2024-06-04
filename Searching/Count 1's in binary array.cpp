class Solution{
public:
    int countOnes(int arr[], int N) {
        int left = 0, right = N - 1;
        int lastOne = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (arr[mid] == 1) {
                lastOne = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return (lastOne != -1) ? lastOne + 1 : 0;
    }
};