class Solution {
public:
    int search(int arr[], int N, int X) {
        // Your code here
        for (int i = 0; i < N; ++i) {
            if (arr[i] == X) {
                return i;
            }
        }
        return -1;
    }
};
-----------------------------------------------------------------------
class Solution {
  public:
    int search(vector<int>& arr, int x) {
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            if (arr[i] == x) {
                return i; // Return 0-based index
            }
        }
        return -1; // Element not found
    }
};
