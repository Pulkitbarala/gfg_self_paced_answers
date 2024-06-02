class Solution {
public:
    int maxOccured(int L[], int R[], int n, int maxx) {
        vector<int> arr(maxx + 2, 0); 
        for (int i = 0; i < n; ++i) {
            arr[L[i]]++;
            if (R[i] + 1 <= maxx) {
                arr[R[i] + 1]--;
            }
        }
        int max_occurrence = arr[0];
        int min_index = 0;
        for (int i = 1; i <= maxx; ++i) {
            arr[i] += arr[i - 1];
            if (arr[i] > max_occurrence) {
                max_occurrence = arr[i];
                min_index = i;
            }
        }

        return min_index;
    }
};