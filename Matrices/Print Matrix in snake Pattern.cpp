class Solution
{   
    public:
    vector<int> snakePattern(vector<vector<int> > matrix)
    {   
        int N = matrix.size();
        vector<int> result;

        for (int i = 0; i < N; i++) {
            if (i % 2 == 0) {
                for (int j = 0; j < N; j++) {
                    result.push_back(matrix[i][j]);
                }
            } else {
                for (int j = N - 1; j >= 0; j--) {
                    result.push_back(matrix[i][j]);
                }
            }
        }

        return result;
    }
};