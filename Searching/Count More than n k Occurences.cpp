class Solution {
public:
    int countOccurence(int arr[], int n, int k) {
        unordered_map<int, int> frequencyMap;
        for (int i = 0; i < n; ++i) {
            frequencyMap[arr[i]]++;
        }
        
        int threshold = n / k;
        int count = 0;
        for (const auto& entry : frequencyMap) {
            if (entry.second > threshold) {
                count++;
            }
        }
        
        return count;
    }
};