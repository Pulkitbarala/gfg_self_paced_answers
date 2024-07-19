class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
        // Create a vector of pairs where each pair is (element, index)
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = {nums[i], i};
        }

        // Sort the array by the elements (first element of pair)
        sort(arr.begin(), arr.end());

        // Create a visited array to track the visited indices
        vector<bool> visited(n, false);

        int swaps = 0;

        for (int i = 0; i < n; ++i) {
            // If the element is already in the correct position or visited
            if (visited[i] || arr[i].second == i) {
                continue;
            }

            // Find the cycle length
            int cycle_length = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = arr[j].second;
                cycle_length++;
            }

            // If there is a cycle of length > 1, it requires (cycle_length - 1) swaps
            if (cycle_length > 1) {
                swaps += (cycle_length - 1);
            }
        }

        return swaps;
    }
};
