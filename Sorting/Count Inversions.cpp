class Solution {
public:
    long long int inversionCount(long long arr[], long long N) {
        long long temp[N];
        return mergeSort(arr, temp, 0, N - 1);
    }

private:
    long long int mergeSort(long long arr[], long long temp[], long long left, long long right) {
        long long mid, inv_count = 0;
        if (left < right) {
            mid = (left + right) / 2;
            inv_count += mergeSort(arr, temp, left, mid);
            inv_count += mergeSort(arr, temp, mid + 1, right);
            inv_count += merge(arr, temp, left, mid + 1, right);
        }
        return inv_count;
    }

    long long int merge(long long arr[], long long temp[], long long left, long long mid, long long right) {
        long long i, j, k;
        long long inv_count = 0;

        i = left;
        j = mid;
        k = left;

        while ((i <= mid - 1) && (j <= right)) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                inv_count += (mid - i);
            }
        }

        while (i <= mid - 1)
            temp[k++] = arr[i++];

        while (j <= right)
            temp[k++] = arr[j++];

        for (i = left; i <= right; i++)
            arr[i] = temp[i];

        return inv_count;
    }
};