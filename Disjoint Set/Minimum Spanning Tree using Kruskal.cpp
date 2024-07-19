class UnionFind {
public:
    vector<int> parent, rank;
    
    UnionFind(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }
    
    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }
    
    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        
        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

long long int kruskalDSU(vector<pair<int, long long int>> adj[], int n, int m) {
    vector<tuple<long long, int, int>> edges;
    for (int u = 1; u <= n; ++u) {
        for (auto it = adj[u].begin(); it != adj[u].end(); ++it) {
            int v = it->first;
            long long w = it->second;
            if (u < v) {
                edges.emplace_back(w, u, v);
            }
        }
    }
    
    sort(edges.begin(), edges.end());
    UnionFind uf(n);
    long long mst_weight = 0;
    for (auto it = edges.begin(); it != edges.end(); ++it) {
        long long w;
        int u, v;
        tie(w, u, v) = *it;
        if (uf.find(u) != uf.find(v)) {
            uf.unionSets(u, v);
            mst_weight += w;
        }
    }
    
    return mst_weight;
}