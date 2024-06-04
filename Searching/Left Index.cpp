int leftIndex(int N, int arr[], int X){
    int left = 0, right = N - 1;
    int result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == X) {
            result = mid;
            right = mid - 1;
        } else if (arr[mid] < X) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
    // Your code here
    
}