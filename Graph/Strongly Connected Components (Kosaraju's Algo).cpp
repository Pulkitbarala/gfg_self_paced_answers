class Solution
{
public:
    // Function to perform DFS and fill the stack with the finish time of nodes
    void dfs1(int v, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& Stack) {
        visited[v] = true;
        for (int u : adj[v]) {
            if (!visited[u]) {
                dfs1(u, adj, visited, Stack);
            }
        }
        Stack.push(v);
    }

    // Function to perform DFS on the transposed graph
    void dfs2(int v, vector<vector<int>>& transposedAdj, vector<bool>& visited) {
        visited[v] = true;
        for (int u : transposedAdj[v]) {
            if (!visited[u]) {
                dfs2(u, transposedAdj, visited);
            }
        }
    }

    // Function to find the number of strongly connected components in the graph
    int kosaraju(int V, vector<vector<int>>& adj) {
        stack<int> Stack;
        vector<bool> visited(V, false);

        // Step 1: Perform DFS to fill the stack with vertices according to their finish time
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                dfs1(i, adj, visited, Stack);
            }
        }

        // Step 2: Transpose the graph
        vector<vector<int>> transposedAdj(V);
        for (int v = 0; v < V; ++v) {
            for (int u : adj[v]) {
                transposedAdj[u].push_back(v);
            }
        }

        // Step 3: Perform DFS on the transposed graph in the order of decreasing finish time
        fill(visited.begin(), visited.end(), false);
        int sccCount = 0;
        while (!Stack.empty()) {
            int v = Stack.top();
            Stack.pop();
            if (!visited[v]) {
                dfs2(v, transposedAdj, visited);
                ++sccCount;
            }
        }

        return sccCount;
    }
};