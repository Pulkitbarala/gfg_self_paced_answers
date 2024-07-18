class Solution
{
    public:
    void findSubsets(vector<int>& arr, int index, vector<int>& current, set<vector<int>>& uniqueSubsets) {
        if (index == arr.size()) {
            uniqueSubsets.insert(current);
            return;
        }
        current.push_back(arr[index]);
        findSubsets(arr, index + 1, current, uniqueSubsets);
        current.pop_back();
        findSubsets(arr, index + 1, current, uniqueSubsets);
    }
    
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        sort(arr.begin(), arr.end());
        set<vector<int>> uniqueSubsets;
        vector<int> current;
        
        findSubsets(arr, 0, current, uniqueSubsets);
        
        vector<vector<int>> result(uniqueSubsets.begin(), uniqueSubsets.end());
        
        return result;
    }
};
