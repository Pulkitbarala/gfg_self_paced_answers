class Solution
{
    public:
    int maxWater(int height[], int n)
    {
        int left = 0;
        int right = n - 1;
        int maximum = 0;
        while (left < right) {
            int current = min(height[left], height[right]) * (right - left - 1);
            maximum = max(maximum, current);
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maximum;
    } 
};