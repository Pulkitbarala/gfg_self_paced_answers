class Solution
{
    public:
    void findMaximumNumHelper(string str, int k, string &max_str, int index) {
        if (k == 0) return;
        
        int n = str.length();
        char max_char = str[index];
        
        for (int i = index + 1; i < n; ++i) {
            if (str[i] > max_char) {
                max_char = str[i];
            }
        }
        
        if (max_char != str[index]) --k;
        
        for (int i = index; i < n; ++i) {
            if (str[i] == max_char) {
                swap(str[index], str[i]);
                if (str.compare(max_str) > 0) {
                    max_str = str;
                }
                findMaximumNumHelper(str, k, max_str, index + 1);
                swap(str[index], str[i]);
            }
        }
    }
    
    string findMaximumNum(string str, int k)
    {
        string max_str = str;
        findMaximumNumHelper(str, k, max_str, 0);
        return max_str;
    }
};
