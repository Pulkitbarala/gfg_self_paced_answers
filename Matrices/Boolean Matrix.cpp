class Solution
{   
public:
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<bool> row(rows, false);
        vector<bool> col(cols, false);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 1) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (row[i] || col[j]) {
                    matrix[i][j] = 1;
                }
            }
        }
    }
};