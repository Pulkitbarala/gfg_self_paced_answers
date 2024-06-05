class Solution
{   
    public:
    int determinantOfMatrix(vector<vector<int>>& matrix, int n)
    {
        if (n == 1) {
            return matrix[0][0];
        }
        
        int det = 0;
        vector<vector<int>> temp(n-1, vector<int>(n-1, 0));
        int sign = 1;
        for (int i = 0; i < n; i++) {
            getCofactor(matrix, temp, 0, i, n);
            det += sign * matrix[0][i] * determinantOfMatrix(temp, n - 1);
            sign = -sign;
        }
        
        return det;
    }
    void getCofactor(vector<vector<int>>& matrix, vector<vector<int>>& temp, int row, int col, int n)
    {
        int tempRow = 0, tempCol = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != row && j != col) {
                    temp[tempRow][tempCol++] = matrix[i][j];
                    if (tempCol == n - 1) {
                        tempRow++;
                        tempCol = 0;
                    }
                }
            }
        }
    }
};