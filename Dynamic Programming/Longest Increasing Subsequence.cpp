class Solution
{
    public:
    int longestSubsequence(int n, int a[])
    {
        vector<int> dp; 
        for (int i = 0; i < n; ++i) {
            auto it = lower_bound(dp.begin(), dp.end(), a[i]);
            
            if (it != dp.end()) {
                *it = a[i];
            } else {
                dp.push_back(a[i]);
            }
        }
        return dp.size();
    }
};