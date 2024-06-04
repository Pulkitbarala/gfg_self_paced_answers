class Solution
{
    public:
    int findNumberOfTriangles(int arr[], int n)
    {
        sort(arr, arr + n);
        
        int count = 0;
        
        for (int i = n - 1; i >= 1; i--) {
            int left = 0, right = i - 1;
            
            while (left < right) {
                if (arr[left] + arr[right] > arr[i]) {
                    count += right - left;
                    right--;
                } else {
                    left++;
                }
            }
        }
        
        return count;
    }
};
