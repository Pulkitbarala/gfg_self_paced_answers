class Solution {
    public:
    void frequencyCount(vector<int>& arr,int N, int P) { 
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            if(arr[i] > n) arr[i] = 0;
        }
        
        P = P + 1;
        
        for(int i = 0; i < n; i++) {
            if(arr[i] % P == 0) continue;
            arr[arr[i] % P - 1] += P;
        }
        
        for(int i = 0; i < n; i++) {
            arr[i] /= P;
        }
    }
};
