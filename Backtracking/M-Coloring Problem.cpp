class Solution {
public:
    bool isSafe(int node, vector<int>& color, bool graph[101][101], int n, int col) {
        for (int k = 0; k < n; k++) {
            if (graph[node][k] && color[k] == col) {
                return false;
            }
        }
        return true;
    }
    
    bool solve(int node, vector<int>& color, int m, int n, bool graph[101][101]) {
        if (node == n) return true;
        
        for (int col = 1; col <= m; col++) {
            if (isSafe(node, color, graph, n, col)) {
                color[node] = col;
                if (solve(node + 1, color, m, n, graph)) return true;
                color[node] = 0;
            }
        }
        
        return false;
    }

    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int> color(n, 0);
        return solve(0, color, m, n, graph);
    }
};