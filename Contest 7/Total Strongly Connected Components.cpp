#include<stack>
class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &finishStack) {
        visited[node] = true;
        for(int neighbor : adj[node]) {
            if(!visited[neighbor]) {
                dfs(neighbor, adj, visited, finishStack);
            }
        }
        finishStack.push(node);
    }

    void reverseDfs(int node, vector<vector<int>> &transposeAdj, vector<bool> &visited) {
        visited[node] = true;
        for(int neighbor : transposeAdj[node]) {
            if(!visited[neighbor]) {
                reverseDfs(neighbor, transposeAdj, visited);
            }
        }
    }

    int solve(int V, int E, vector<int> &a) {
        vector<vector<int>> adj(V);
        vector<vector<int>> transposeAdj(V);
        
        for(int i = 0; i < 2 * E; i += 2) {
            int u = a[i];
            int v = a[i + 1];
            adj[u].push_back(v);
            transposeAdj[v].push_back(u);
        }
        
        vector<bool> visited(V, false);
        stack<int> finishStack;
        
        for(int i = 0; i < V; i++) {
            if(!visited[i]) {
                dfs(i, adj, visited, finishStack);
            }
        }
        fill(visited.begin(), visited.end(), false);
        
        int sccCount = 0;
        while(!finishStack.empty()) {
            int node = finishStack.top();
            finishStack.pop();
            
            if(!visited[node]) {
                sccCount++;
                reverseDfs(node, transposeAdj, visited);
            }
        }
        
        return sccCount;
    }
};