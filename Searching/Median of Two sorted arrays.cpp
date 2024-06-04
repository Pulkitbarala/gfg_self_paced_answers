//User function template for C++


class Solution
{
    public:
    int findMedian(int arr[], int n, int brr[], int m)
    {
        if (n > m)
            return findMedian(brr, m, arr, n);
        
        int minIdx = 0, maxIdx = n, i, j;
        int median;
        
        while (minIdx <= maxIdx)
        {
            i = (minIdx + maxIdx) / 2;
            j = ((n + m + 1) / 2) - i;
            
            if (i < n && j > 0 && brr[j - 1] > arr[i])
                minIdx = i + 1;
            else if (i > 0 && j < m && arr[i - 1] > brr[j])
                maxIdx = i - 1;
            else
            {
                int maxLeft = 0;
                if (i == 0)
                    maxLeft = brr[j - 1];
                else if (j == 0)
                    maxLeft = arr[i - 1];
                else
                    maxLeft = max(arr[i - 1], brr[j - 1]);
                
                if ((n + m) % 2 == 1)
                    return maxLeft;
                
                int minRight = 0;
                if (i == n)
                    minRight = brr[j];
                else if (j == m)
                    minRight = arr[i];
                else
                    minRight = min(arr[i], brr[j]);
                
                return (maxLeft + minRight) / 2;
            }
        }
        
        return 0;
    }
};