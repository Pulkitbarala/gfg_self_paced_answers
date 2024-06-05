class Solution
{   
    public:
    vector<int> sumTriangles(const vector<vector<int>>& matrix, int n)
    {
        int upperSum = 0, lowerSum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i <= j) {
                    upperSum += matrix[i][j];
                }
                if (i >= j) {
                    lowerSum += matrix[i][j];
                }
            }
        }
        
        return {upperSum, lowerSum};
    }
};