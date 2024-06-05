class Solution {
public:
    int countNonRepeated(int arr[], int n) {
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;
        }

        int count = 0;
        for (const auto &entry : freq) {
            if (entry.second == 1) {
                count++;
            }
        }

        return count;
    }
};