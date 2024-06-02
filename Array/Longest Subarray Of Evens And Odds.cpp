class Solution{
    public:
    int maxEvenOdd(int arr[], int n) 
    { 
        int maxLength = 1;
        int currentLength = 1;
        for(int i = 1; i < n; i++) {
            if ((arr[i] % 2 == 0 && arr[i - 1] % 2 != 0) ||
                (arr[i] % 2 != 0 && arr[i - 1] % 2 == 0)) {
                currentLength++;
            } else {
                maxLength = max(maxLength, currentLength);
                currentLength = 1;
            }
        }
        
        maxLength = max(maxLength, currentLength);
        return maxLength;
    } 
};