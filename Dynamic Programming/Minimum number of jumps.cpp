class Solution {
public:
    int minimumJumps(int arr[], int n) {
        if (n <= 1) return 0;
        if (arr[0] == 0) return -1;

        int maxReach = arr[0];
        int steps = arr[0];
        int jumps = 1;

        for (int i = 1; i < n; ++i) {
            if (i == n - 1) return jumps;

            maxReach = max(maxReach, i + arr[i]);
            --steps;

            if (steps == 0) {
                ++jumps;

                if (i >= maxReach) return -1;
                steps = maxReach - i;
            }
        }

        return -1;
    }
};