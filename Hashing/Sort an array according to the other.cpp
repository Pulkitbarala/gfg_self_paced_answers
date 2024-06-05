class Solution{
    public:
    vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) 
    {
        unordered_map<int, int> freq;
        for (int num : A1) {
            freq[num]++;
        }
        vector<int> result;
        for (int num : A2) {
            if (freq.find(num) != freq.end()) {
                int count = freq[num];
                while (count--) {
                    result.push_back(num);
                }
                freq.erase(num);
            }
        }
        vector<int> remaining;
        for (auto& entry : freq) {
            int num = entry.first;
            int count = entry.second;
            while (count--) {
                remaining.push_back(num);
            }
        }
        sort(remaining.begin(), remaining.end());
        result.insert(result.end(), remaining.begin(), remaining.end());
        
        return result;
    } 
};