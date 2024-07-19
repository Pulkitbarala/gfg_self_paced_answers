class Solution
{
public:
    // Directions for 8-directional connectivity
    vector<int> dirX = {1, -1, 0, 0, 1, -1, 1, -1};
    vector<int> dirY = {0, 0, 1, -1, 1, 1, -1, -1};

    // Function to perform DFS and calculate area
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int& area) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Base cases
        if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y] || grid[x][y] == 0) 
            return;

        // Mark this cell as visited
        visited[x][y] = true;
        area++; // Increment the area for the current component

        // Explore all 8 possible directions
        for (int i = 0; i < 8; ++i) {
            int newX = x + dirX[i];
            int newY = y + dirY[i];
            dfs(grid, visited, newX, newY, area);
        }
    }

    // Function to find the unit area of the largest region of 1s
    int findMaxArea(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int maxArea = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int area = 0;
                    dfs(grid, visited, i, j, area);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};