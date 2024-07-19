class Solution 
{
public:
    // Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int>& KnightPos, vector<int>& TargetPos, int N)
    {
        // Directions a Knight can move in chess
        vector<vector<int>> directions = {
            {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
            {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
        };
        
        // BFS queue and visited array
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(N + 1, vector<bool>(N + 1, false));
        
        // Starting position
        int startX = KnightPos[0];
        int startY = KnightPos[1];
        int targetX = TargetPos[0];
        int targetY = TargetPos[1];
        
        // If starting position is the same as target position
        if (startX == targetX && startY == targetY)
            return 0;
        
        // Initialize BFS
        q.push({startX, startY});
        visited[startX][startY] = true;
        
        // Number of moves taken
        int moves = 0;
        
        while (!q.empty()) {
            int size = q.size();
            moves++;
            
            for (int i = 0; i < size; i++) {
                auto front = q.front(); // Get the front element
                q.pop();
                
                int x = front.first; // Access the row
                int y = front.second; // Access the column
                
                for (auto& dir : directions) {
                    int newX = x + dir[0];
                    int newY = y + dir[1];
                    
                    // Check if the new position is within bounds and not visited
                    if (newX >= 1 && newX <= N && newY >= 1 && newY <= N && !visited[newX][newY]) {
                        if (newX == targetX && newY == targetY)
                            return moves;
                        
                        q.push({newX, newY});
                        visited[newX][newY] = true;
                    }
                }
            }
        }
        
        // Target not reachable
        return -1;
    }
};