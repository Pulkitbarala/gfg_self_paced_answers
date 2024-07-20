class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        int mn[n], mx[n];
        mn[0] = arr[0];
        for(int i=1; i<n; i++){
            mn[i] = min(mn[i-1], arr[i]);
        }
        
        mx[n-1]=arr[n-1];
        for(int i=n-2; i>=0; i--){
            mx[i] = max(mx[i+1], arr[i]);
        }
        
        int i=0, j=0, ans=-1;
        while(i<n && j<n){
            if(mn[i] <= mx[j]){
                ans = max(ans, j-i);
                j += 1;
            }else{
                i += 1;
            }
        }
        return ans;
    }

};
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    int maxIndexDiff(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;

        vector<int> leftMin(n);
        vector<int> rightMax(n);

        // Fill leftMin[] such that leftMin[i] contains the minimum value from arr[0] to arr[i]
        leftMin[0] = arr[0];
        for (int i = 1; i < n; ++i) {
            leftMin[i] = min(arr[i], leftMin[i-1]);
        }

        // Fill rightMax[] such that rightMax[j] contains the maximum value from arr[j] to arr[n-1]
        rightMax[n-1] = arr[n-1];
        for (int j = n-2; j >= 0; --j) {
            rightMax[j] = max(arr[j], rightMax[j+1]);
        }

        // Traverse leftMin[] and rightMax[] to find the maximum j - i
        int i = 0, j = 0, maxDiff = 0;
        while (i < n && j < n) {
            if (leftMin[i] <= rightMax[j]) {
                maxDiff = max(maxDiff, j - i);
                ++j;
            } else {
                ++i;
            }
        }

        return maxDiff;
    }
};
