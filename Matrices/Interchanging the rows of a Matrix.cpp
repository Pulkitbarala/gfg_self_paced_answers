class Solution
{   
public:
    void interchangeRows(vector<vector<int> > &matrix)
    {
        int n = matrix.size();
        if (n == 0)
            return;
        int m = matrix[0].size();
        if (m == 0)
            return;

        int start = 0, end = n - 1;
        while (start < end)
        {
            swap(matrix[start], matrix[end]);
            start++;
            end--;
        }
    }
};