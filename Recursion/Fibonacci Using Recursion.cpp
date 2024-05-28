//User function Template for C++

class Solution {
public:
    // Function to calculate the nth Fibonacci number iteratively
    int fibonacci(int n) {
        if (n <= 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else {
            int a = 0, b = 1, c;
            for (int i = 2; i <= n; ++i) {
                c = a + b;
                a = b;
                b = c;
            }
            return b;
        }
    }
};