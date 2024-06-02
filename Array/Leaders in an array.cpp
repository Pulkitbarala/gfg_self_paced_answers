    

class Solution{
    public:
    vector<int> leaders(int a[], int n) {
        vector<int> result;
        int max_from_right = a[n-1];
        result.push_back(max_from_right);
        for (int i = n-2; i >= 0; i--) {
            if (a[i] >= max_from_right) {
                max_from_right = a[i];
                result.push_back(max_from_right);
            }
        }
        reverse(result.begin(), result.end());
        
        return result;
    }
};