class Solution {
public:
    // Directions for 8 possible moves (up, down, left, right, and 4 diagonals)
    vector<int> dirX = {-1, 1, 0, 0, -1, -1, 1, 1};
    vector<int> dirY = {0, 0, -1, 1, -1, 1, -1, 1};
    
    // Function to perform DFS traversal
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y, int n, int m) {
        visited[x][y] = true; // Mark the cell as visited
        
        for (int i = 0; i < 8; ++i) {
            int newX = x + dirX[i];
            int newY = y + dirY[i];
            
            // Check if the new cell is within bounds and is land and not visited
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == '1' && !visited[newX][newY]) {
                dfs(grid, visited, newX, newY, n, m);
            }
        }
    }
    
    // Function to find the number of islands
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Initialize the visited array
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        int count = 0;
        
        // Iterate over all cells in the grid
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // If the cell is land and not visited, start a DFS
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(grid, visited, i, j, n, m);
                    count++; // Increment the island count
                }
            }
        }
        
        return count;
    }
};