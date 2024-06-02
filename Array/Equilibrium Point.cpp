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