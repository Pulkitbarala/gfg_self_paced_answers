
class Solution{
public:
    // Function to find the trapped water between the blocks.
    long long trappingWater(int arr[], int n){
        // If there are less than 3 blocks, no water can be trapped
        if (n < 3) {
            return 0;
        }
        
        // Arrays to store the maximum height to the left and right of each block
        vector<int> left_max(n, 0);
        vector<int> right_max(n, 0);
        
        // Initialize the leftmost and rightmost values
        left_max[0] = arr[0];
        right_max[n-1] = arr[n-1];
        
        // Fill left_max array
        for (int i = 1; i < n; i++) {
            left_max[i] = max(left_max[i-1], arr[i]);
        }
        
        // Fill right_max array
        for (int i = n-2; i >= 0; i--) {
            right_max[i] = max(right_max[i+1], arr[i]);
        }
        
        // Calculate the total trapped water
        long long total_water = 0;
        for (int i = 0; i < n; i++) {
            total_water += min(left_max[i], right_max[i]) - arr[i];
        }
        
        return total_water;
    }
};
