class Solution{
public:
    vector<vector<int> > stockBuySell(vector<int> A, int n){
        vector<vector<int>> result;
        
        int i = 0;
        while (i < n - 1) {
            while (i < n - 1 && A[i + 1] <= A[i]) {
                i++;
            }
            if (i == n - 1) break;
            int buy = i++;
            while (i < n && A[i] >= A[i - 1]) {
                i++;
            }
            int sell = i - 1;
            
            result.push_back({buy, sell});
        }
        
        return result;
    }
};