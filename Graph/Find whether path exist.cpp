class Solution {
public:
    // Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int, int>> q;
        int startX, startY, endX, endY;

        // Find the source and destination
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                }
                if (grid[i][j] == 2) {
                    endX = i;
                    endY = j;
                }
            }
        }

        // Directions for moving up, down, left, and right
        vector<int> dirX = {-1, 1, 0, 0};
        vector<int> dirY = {0, 0, -1, 1};

        // Start BFS from the source
        q.push({startX, startY});
        visited[startX][startY] = true;

        while (!q.empty()) {
            pair<int, int> current = q.front();
            q.pop();

            int x = current.first;
            int y = current.second;

            // Check if we have reached the destination
            if (x == endX && y == endY) {
                return true;
            }

            // Explore all 4 possible directions
            for (int i = 0; i < 4; ++i) {
                int newX = x + dirX[i];
                int newY = y + dirY[i];

                // Check if new position is valid
                if (newX >= 0 && newX < n && newY >= 0 && newY < n && !visited[newX][newY] && grid[newX][newY] != 0) {
                    visited[newX][newY] = true;
                    q.push({newX, newY});
                }
            }
        }

        // If we exit the loop without finding the destination
        return false;
    }
};