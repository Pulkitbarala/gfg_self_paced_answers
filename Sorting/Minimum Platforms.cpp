class Solution{
    public:
    int findPlatform(int arr[], int dep[], int n) {
        sort(arr, arr + n);
        sort(dep, dep + n);
        
        int platforms_needed = 1;
        int max_platforms = 1;
        int i = 1;
        int j = 0;
        
        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {
                platforms_needed++;
                i++;
            }
            else {
                platforms_needed--;
                j++;
            }
            max_platforms = max(max_platforms, platforms_needed);
        }
        
        return max_platforms;
    }
};