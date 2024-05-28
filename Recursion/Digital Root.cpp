class Solution {
public:
    //Complete this function
    int digitalRoot(int n) {
        if (n == 0) return 0;
        return 1 + (n - 1) % 9;
    }
};