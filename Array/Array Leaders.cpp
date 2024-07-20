class Solution {
  public:
    vector<int> leaders(int n, int arr[]) {
        vector<int> result;
        int max_from_right = arr[n-1];
        
        result.push_back(max_from_right);
        
        for (int i = n-2; i >= 0; i--) {
            if (arr[i] >= max_from_right) {
                max_from_right = arr[i];
                result.push_back(max_from_right);
            }
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
