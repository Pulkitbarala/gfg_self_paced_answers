class Solution
{
    public:
    // Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int shapeCount = 0;
        
        // Direction vectors for up, down, left, right
        vector<int> dirX = {-1, 1, 0, 0};
        vector<int> dirY = {0, 0, -1, 1};
        
        // Helper function for DFS
        auto dfs = [&](int x, int y) {
            stack<pair<int, int>> s;
            s.push(make_pair(x, y));
            visited[x][y] = true;
            
            while (!s.empty()) {
                pair<int, int> current = s.top();
                s.pop();
                int cx = current.first;
                int cy = current.second;
                
                // Explore all 4 directions
                for (int i = 0; i < 4; i++) {
                    int nx = cx + dirX[i];
                    int ny = cy + dirY[i];
                    
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 'X' && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        s.push(make_pair(nx, ny));
                    }
                }
            }
        };
        
        // Iterate through each cell in the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'X' && !visited[i][j]) {
                    // Found an unvisited 'X', start a new DFS
                    dfs(i, j);
                    shapeCount++;
                }
            }
        }
        
        return shapeCount;
    }
};