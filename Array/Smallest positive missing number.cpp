
class Solution {
public:
    int missingNumber(int arr[], int n) { 
        int shift = segregate(arr, n);
        return findMissingPositive(arr + shift, n - shift);
    }

private:
    int segregate(int arr[], int n) {
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] <= 0) {
                swap(arr[i], arr[j]);
                j++;
            }
        }
        return j;
    }
    int findMissingPositive(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            int val = abs(arr[i]);
            if (val - 1 < n && arr[val - 1] > 0) {
                arr[val - 1] = -arr[val - 1];
            }
        }

        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                return i + 1;
            }
        }

        return n + 1;
    }
};