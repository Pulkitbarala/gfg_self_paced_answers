class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
        if (n == 1) return 1; // If there's only one element, it's the equilibrium point
        
        long long total_sum = 0;
        for (int i = 0; i < n; i++) {
            total_sum += a[i];
        }
        
        long long left_sum = 0;
        for (int i = 0; i < n; i++) {
            total_sum -= a[i]; // Update total sum by subtracting current element
            if (left_sum == total_sum) return i + 1; // Equilibrium point found
            left_sum += a[i]; // Update left sum
        }
        
        return -1; // No equilibrium point found
    }
};
-------------------------------------------------------------------------------------------------------------------------
class Solution {
  public:
    int equilibriumPoint(vector<long long> &arr) {
        int n = arr.size();
        if (n == 1) return 1; // If there's only one element, it's the equilibrium point

        long long totalSum = accumulate(arr.begin(), arr.end(), 0LL);
        long long leftSum = 0;

        for (int i = 0; i < n; ++i) {
            totalSum -= arr[i]; // totalSum now represents the sum of elements right of the current index

            if (leftSum == totalSum) {
                return i + 1; // Returning 1-based index
            }

            leftSum += arr[i]; // Updating leftSum for the next iteration
        }

        return -1; // If no equilibrium point is found
    }
};
