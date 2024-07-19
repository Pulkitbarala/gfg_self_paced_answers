class Solution {
  public:
    // Function to perform DFS and detect cycles
    bool dfs(int node, vector<int> adj[], vector<bool> &visited, vector<bool> &recStack) {
        // Mark the current node as visited and add it to the recursion stack
        visited[node] = true;
        recStack[node] = true;
        
        // Recur for all the vertices adjacent to this vertex
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                // If the neighbor hasn't been visited, recurse on it
                if (dfs(neighbor, adj, visited, recStack)) {
                    return true;
                }
            } else if (recStack[neighbor]) {
                // If the neighbor is in the recursion stack, a cycle is detected
                return true;
            }
        }
        
        // Remove the vertex from the recursion stack
        recStack[node] = false;
        return false;
    }

    // Function to detect cycle in a directed graph
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);

        // Check for cycles in each component
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, recStack)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};