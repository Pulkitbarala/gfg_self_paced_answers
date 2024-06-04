class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x){
        int left = 0, right = n - 1;
        int result = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (v[mid] <= x) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result; 
        // Your code here
        
    }
};