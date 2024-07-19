class Solution {
public:
    // Function to find the minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;
        int freshCount = 0;
        
        // Initialize the queue with all rotten oranges and count fresh oranges
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }
        
        int time = 0;
        
        while (!q.empty()) {
            int size = q.size();
            bool rotten = false;
            
            for (int i = 0; i < size; ++i) {
                // Use std::pair instead of structured binding
                pair<int, int> p = q.front();
                q.pop();
                
                int r = p.first;
                int c = p.second;
                
                for (auto dir : directions) {
                    int newRow = r + dir[0];
                    int newCol = c + dir[1];
                    
                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 2;
                        q.push({newRow, newCol});
                        freshCount--;
                        rotten = true;
                    }
                }
            }
            
            if (rotten) {
                ++time;
            }
        }
        
        return freshCount == 0 ? time : -1;
    }
};