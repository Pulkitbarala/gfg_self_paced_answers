class Solution
{
public:
    int find(int x, vector<int>& parent) {
        if (parent[x] != x) {
            parent[x] = find(parent[x], parent);
        }
        return parent[x];
    }
    
    void union_(int a, int b, vector<int>& parent, vector<int>& rank) {
        int rootA = find(a, parent);
        int rootB = find(b, parent);

        if (rootA != rootB) {
            if (rank[rootA] > rank[rootB]) {
                parent[rootB] = rootA;
            } else if (rank[rootA] < rank[rootB]) {
                parent[rootA] = rootB;
            } else {
                parent[rootB] = rootA;
                rank[rootA]++;
            }
        }
    }
    
    int detectCycle(int V, vector<int> adj[]) {
        vector<int> parent(V);
        vector<int> rank(V, 0);
        for (int i = 0; i < V; ++i) {
            parent[i] = i;
        }

        for (int u = 0; u < V; ++u) {
            for (int v : adj[u]) {
                if (u < v) {
                    int rootU = find(u, parent);
                    int rootV = find(v, parent);

                    if (rootU == rootV) {
                        return 1;
                    }
                    union_(u, v, parent, rank);
                }
            }
        }
        return 0; // No cycle detected
    }
};
