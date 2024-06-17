class Solution {
public:
    string countSort(string arr) {
        int n = arr.length();
        vector<int> count(RANGE + 1, 0);
        string output(n, ' ');
        
        for (int i = 0; i < n; ++i)
            ++count[arr[i]];
        
        for (int i = 1; i <= RANGE; ++i)
            count[i] += count[i - 1];
        
        for (int i = n - 1; i >= 0; --i) {
            output[count[arr[i]] - 1] = arr[i];
            --count[arr[i]];
        }
        
        return output;
    }
};
