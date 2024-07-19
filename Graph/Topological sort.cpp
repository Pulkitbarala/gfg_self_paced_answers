class Solution {
public:
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> inDegree(V, 0);
        vector<int> topoOrder;
        queue<int> q;

        // Calculate in-degrees
        for (int i = 0; i < V; i++) {
            for (int v : adj[i]) {
                inDegree[v]++;
            }
        }

        // Enqueue vertices with in-degree 0
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        // Process the queue
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topoOrder.push_back(u);

            // Decrease in-degree of adjacent vertices
            for (int v : adj[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return topoOrder;
    }
};