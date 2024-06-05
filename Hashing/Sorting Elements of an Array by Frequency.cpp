class Solution {
public:
    vector<int> sortByFreq(int arr[], int n) {
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;
        }
        auto comp = [&](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second == b.second) {
                return a.first > b.first;
            }
            return a.second < b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        for (auto& entry : freq) {
            pq.push(entry);
        }
        vector<int> result;
        while (!pq.empty()) {
            auto entry = pq.top();
            pq.pop();
            for (int i = 0; i < entry.second; i++) {
                result.push_back(entry.first);
            }
        }
        
        return result;
    }
};