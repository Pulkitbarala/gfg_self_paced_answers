class Solution 
{
    public:
    // Function to perform DFS and mark visited nodes
    void DFS(int v, vector<int> adj[], vector<bool> &visited) {
        stack<int> stk;
        stk.push(v);
        visited[v] = true;
        
        while (!stk.empty()) {
            int node = stk.top();
            stk.pop();
            
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    stk.push(neighbor);
                }
            }
        }
    }

    // Function to find a Mother Vertex in the Graph
    int findMotherVertex(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        int potentialMother = -1;

        // Step 1: Find a potential mother vertex
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                DFS(i, adj, visited);
                potentialMother = i; // Update potential mother vertex
            }
        }

        // Step 2: Verify if the potential mother vertex is actually a mother vertex
        fill(visited.begin(), visited.end(), false); // Reset visited array
        DFS(potentialMother, adj, visited);

        // Check if all vertices are reachable from the potential mother vertex
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                return -1; // If any vertex is not reachable, return -1
            }
        }

        return potentialMother; // Return the valid mother vertex
    }
};