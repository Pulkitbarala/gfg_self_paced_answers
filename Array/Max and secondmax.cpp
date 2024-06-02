class Solution {
  public:
    vector<int> largestAndSecondLargest(int sizeOfArray, int arr[]) {
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        
        for (int i = 0; i < sizeOfArray; i++) {
            if (arr[i] > max1) {
                max2 = max1;
                max1 = arr[i];
            } else if (arr[i] > max2 && arr[i] != max1) {
                max2 = arr[i];
            }
        }
        
        if (max2 == INT_MIN) {
            max2 = -1;
        }
        
        return {max1, max2};
    }
};