class Solution{
public:
    // Function to calculate power recursively
    int RecursivePower(int n, int p) {
        // Base case
        if (p == 0) {
            return 1;
        } else {
            // Recursive case
            return n * RecursivePower(n, p - 1);
        }
    }
};