
class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    q.push(make_pair(i, j));
                    distance[i][j] = 0;
                }
            }
        }
        
        vector<int> dRow = {-1, 1, 0, 0};
        vector<int> dCol = {0, 0, -1, 1};
        
        while (!q.empty()) {
            pair<int, int> front = q.front();
            q.pop();
            int row = front.first;
            int col = front.second;
            
            for (int i = 0; i < 4; ++i) {
                int newRow = row + dRow[i];
                int newCol = col + dCol[i];
                
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                    if (distance[newRow][newCol] > distance[row][col] + 1) {
                        distance[newRow][newCol] = distance[row][col] + 1;
                        q.push(make_pair(newRow, newCol));
                    }
                }
            }
        }
        
        return distance;
    }
};