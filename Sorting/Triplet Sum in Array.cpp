class Solution {
public:
    bool find3Numbers(int A[], int n, int X) {
        sort(A, A + n);
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;
            int target = X - A[i];
            while (left < right) {
                int current_sum = A[left] + A[right];
                if (current_sum == target)
                    return true;
                else if (current_sum < target)
                    left++;
                else
                    right--;
            }
        }
        return false;
    }
};