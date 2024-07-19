class Solution {
  public:
    // Helper function for DFS
    bool dfs(int node, vector<int> adj[], vector<bool>& visited, int parent) {
        visited[node] = true;
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, adj, visited, node)) {
                    return true;
                }
            } else if (neighbor != parent) {
                // If the neighbor is visited and is not the parent, a cycle is found
                return true;
            }
        }
        return false;
    }

    // Function to detect cycle in an undirected graph
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, -1)) {
                    return true;
                }
            }
        }
        return false;
    }
};