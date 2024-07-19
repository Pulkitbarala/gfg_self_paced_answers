class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> result;       // To store the DFS traversal order
        vector<bool> visited(V, false); // To keep track of visited nodes
        
        // Helper function for DFS
        function<void(int)> dfs = [&](int v) {
            visited[v] = true;       // Mark the current node as visited
            result.push_back(v);     // Add the node to the result list
            
            for (int neighbor : adj[v]) { // Visit all adjacent nodes
                if (!visited[neighbor]) {
                    dfs(neighbor);   // Recursive call for unvisited neighbors
                }
            }
        };
        
        // Start DFS from vertex 0
        dfs(0);
        
        return result;
    }
};