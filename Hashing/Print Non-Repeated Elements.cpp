class Solution {
public:
    vector<int> printNonRepeated(int arr[], int n) {
        unordered_map<int, int> freq;
        vector<int> result;
        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;
        }
        for (int i = 0; i < n; i++) {
            if (freq[arr[i]] == 1) {
                result.push_back(arr[i]);
            }
        }

        return result;
    }
};