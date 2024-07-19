class Solution {
public:
    // Function to count paths between two vertices in a directed graph.
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        // Memoization table
        vector<int> memo(V, -1);
        return dfs(source, destination, adj, memo);
    }

private:
    // DFS function with memoization
    int dfs(int node, int destination, vector<int> adj[], vector<int>& memo) {
        // If we've already computed the number of paths from this node, return it
        if (memo[node] != -1) {
            return memo[node];
        }
        
        // If the current node is the destination, there's exactly one path
        if (node == destination) {
            return memo[node] = 1;
        }
        
        int pathCount = 0;
        // Explore all adjacent nodes
        for (int neighbor : adj[node]) {
            pathCount += dfs(neighbor, destination, adj, memo);
        }
        
        // Memoize the result
        return memo[node] = pathCount;
    }
};