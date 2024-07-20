class Solution {
  public:
    int maxOccured(int n, int l[], int r[], int maxx) {
        vector<int> arr(maxx + 2, 0);
        for (int i = 0; i < n; i++) {
            arr[l[i]] += 1;
            arr[r[i] + 1] -= 1;
        }
        int max_occurrence = arr[0];
        int result = 0;
        for (int i = 1; i <= maxx; i++) {
            arr[i] += arr[i - 1];
            if (arr[i] > max_occurrence) {
                max_occurrence = arr[i];
                result = i;
            }
        }
        return result;
    }
};
