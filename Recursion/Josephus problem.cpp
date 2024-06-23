/*You are required to complete this method */

class Solution {
public:
    int josephus(int n, int k) {
        // Base case
        if (n == 1) return 1;
        
        // Recursive step
        return (josephus(n - 1, k) + k - 1) % n + 1;
    }
};
