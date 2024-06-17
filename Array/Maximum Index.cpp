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