class Solution
{
    public:
    // Function to find the level of node X.
    int nodeLevel(int V, vector<int> adj[], int X) 
    {
        // Edge case: If X is node 0
        if (X == 0) return 0;

        // BFS initialization
        vector<int> distance(V, -1); // Distance array to store levels
        queue<int> q;
        vector<bool> visited(V, false); // Visited array to avoid re-processing

        // Start BFS from node 0
        q.push(0);
        visited[0] = true;
        distance[0] = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    distance[neighbor] = distance[node] + 1;
                    q.push(neighbor);

                    // If we found the target node
                    if (neighbor == X)
                    {
                        return distance[neighbor];
                    }
                }
            }
        }

        // If node X was not found
        return -1;
    }
};