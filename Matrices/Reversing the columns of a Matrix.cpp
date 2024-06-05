class Solution
{   
public:
    void reverseCol(vector<vector<int> > &matrix)
    {
        int n = matrix.size();
        if (n == 0)
            return;
        int m = matrix[0].size();
        if (m == 0)
            return;

        for (int i = 0; i < n; i++)
        {
            int left = 0, right = m - 1;
            while (left < right)
            {
                swap(matrix[i][left], matrix[i][right]);
                left++;
                right--;
            }
        }
    }
};