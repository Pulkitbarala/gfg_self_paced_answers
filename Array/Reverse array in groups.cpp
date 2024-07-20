//User function template for C++

class Solution {
public:
    void reverseInGroups(vector<long long>& arr, int n, int k) {
        for (int i = 0; i < n; i += k) {
            int left = i;
            int right = min(i + k - 1, n - 1);
            while (left < right) {
                swap(arr[left], arr[right]);
                left++;
                right--;
            }
        }
    }
};
---------------------------------------------------------------------------------------
class Solution {
  public:
    void reverseInGroups(vector<long long int> &arr, int k) {
        int n = arr.size();
        for (int i = 0; i < n; i += k) {
            int left = i;
            int right = min(i + k - 1, n - 1);
            while (left < right) {
                swap(arr[left], arr[right]);
                left++;
                right--;
            }
        }
    }
};
