class Solution {
public:
    vector<vector<int>> tarjans(int V, vector<int> adj[]) {
        vector<vector<int>> result;
        vector<int> disc(V, -1);
        vector<int> low(V, -1);
        vector<bool> inStack(V, false);
        stack<int> st;
        int time = 0;

        function<void(int)> dfs = [&](int u) {
            disc[u] = low[u] = time++;
            st.push(u);
            inStack[u] = true;

            for (int v : adj[u]) {
                if (disc[v] == -1) {  // If v is not visited
                    dfs(v);
                    low[u] = min(low[u], low[v]);
                } else if (inStack[v]) {  // If v is in the stack
                    low[u] = min(low[u], disc[v]);
                }
            }

            // If u is a root node, pop the stack and generate an SCC
            if (disc[u] == low[u]) {
                vector<int> scc;
                while (st.top() != u) {
                    scc.push_back(st.top());
                    inStack[st.top()] = false;
                    st.pop();
                }
                scc.push_back(st.top());
                inStack[st.top()] = false;
                st.pop();
                sort(scc.begin(), scc.end());  // Sort the SCC
                result.push_back(scc);
            }
        };

        for (int i = 0; i < V; ++i) {
            if (disc[i] == -1) {
                dfs(i);
            }
        }

        // Sort the list of SCCs lexicographically
        sort(result.begin(), result.end());

        return result;
    }
};