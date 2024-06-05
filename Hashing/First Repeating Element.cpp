class Solution {
  public:
    int firstRepeated(int arr[], int n) {
        unordered_map<int, pair<int, int>> mp;
        
        for (int i = 0; i < n; ++i) {
            if (mp.find(arr[i]) != mp.end()) {
                mp[arr[i]].first++;
            } else {
                mp[arr[i]] = {1, i + 1};
            }
        }
        
        int minIndex = INT_MAX;
        for (auto& entry : mp) {
            if (entry.second.first > 1 && entry.second.second < minIndex) {
                minIndex = entry.second.second;
            }
        }
        
        return (minIndex == INT_MAX) ? -1 : minIndex;
    }
};