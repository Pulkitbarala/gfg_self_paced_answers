class Solution {
public:
    void segragate012(int arr[], int N) {
        int low = 0, mid = 0, high = N - 1;
        
        while (mid <= high) {
            switch (arr[mid]) {
                case 0:
                    swap(arr[low++], arr[mid++]);
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(arr[mid], arr[high--]);
                    break;
            }
        }
    }
};