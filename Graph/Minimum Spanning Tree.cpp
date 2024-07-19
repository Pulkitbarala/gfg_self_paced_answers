class Solution
{
public:
    // Helper function to find the root of an element
    int find(int parent[], int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent, parent[i]); // Path compression
    }

    // Helper function to union two subsets
    void unionSets(int parent[], int rank[], int x, int y) {
        int rootX = find(parent, x);
        int rootY = find(parent, y);

        if (rootX != rootY) {
            // Union by rank
            if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

    // Function to find sum of weights of edges of the Minimum Spanning Tree
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // Create a list to store all edges
        vector<tuple<int, int, int>> edges; // (weight, u, v)

        // Populate the edges list
        for (int i = 0; i < V; i++) {
            for (const auto& edge : adj[i]) {
                int u = i;
                int v = edge[0];
                int w = edge[1];
                if (u < v) {
                    edges.emplace_back(w, u, v);
                }
            }
        }

        // Sort edges based on their weight
        sort(edges.begin(), edges.end());

        // Initialize Union-Find structure
        int parent[V];
        int rank[V];
        iota(parent, parent + V, 0); // parent[i] = i
        fill(rank, rank + V, 0);

        int mst_weight = 0;

        // Kruskal's Algorithm
        for (const auto& edge : edges) {
            int w, u, v;
            tie(w, u, v) = edge;
            if (find(parent, u) != find(parent, v)) {
                unionSets(parent, rank, u, v);
                mst_weight += w;
            }
        }

        return mst_weight;
    }
};