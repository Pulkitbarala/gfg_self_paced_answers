class Solution
{
public:
    void exchangeColumns(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        if (n == 0)
            return;
        int m = matrix[0].size();
        if (m == 0)
            return;

        for (int i = 0; i < n; i++)
        {
            swap(matrix[i][0], matrix[i][m - 1]);
        }
    }
};