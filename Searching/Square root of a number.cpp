class Solution {
public:
    long long int floorSqrt(long long int x) {
        if (x == 0 || x == 1) 
            return x;
        
        long long int left = 1, right = x, ans = 0;
        
        while (left <= right) {
            long long int mid = (left + right) / 2;
            if (mid * mid == x) 
                return mid;
            if (mid * mid < x) {
                left = mid + 1;
                ans = mid;
            } 
            else {
                right = mid - 1;
            }
        }
        
        return ans;
    }
};