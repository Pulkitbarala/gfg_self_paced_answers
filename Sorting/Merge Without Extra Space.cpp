class Solution {
public:
    void merge(long long arr1[], long long arr2[], int n, int m) {
        int total = n + m;
        int gap = (total + 1) / 2;

        while (gap > 0) {
            int i = 0;
            int j = gap;
            while (j < total) {
                if (j < n && arr1[i] > arr1[j]) {
                    swap(arr1[i], arr1[j]);
                } else if (j >= n && i < n && arr1[i] > arr2[j - n]) {
                    swap(arr1[i], arr2[j - n]);
                } else if (j >= n && i >= n && arr2[i - n] > arr2[j - n]) {
                    swap(arr2[i - n], arr2[j - n]);
                }
                i++;
                j++;
            }
            if (gap == 1) break;
            gap = (gap + 1) / 2;
        }
    }
};