class Solution {
private:
    vector<int> parent;
    
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }
    
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        int n = accounts.size();
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        
        unordered_map<string, int> emailToIdx;
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < accounts[i].size(); ++j) {
                if (emailToIdx.count(accounts[i][j]) == 0) {
                    emailToIdx[accounts[i][j]] = i;
                } else {
                    unite(i, emailToIdx[accounts[i][j]]);
                }
            }
        }
        
        unordered_map<int, set<string>> mergedAccounts;
        for (int i = 0; i < n; ++i) {
            int root = find(i);
            for (int j = 1; j < accounts[i].size(); ++j) {
                mergedAccounts[root].insert(accounts[i][j]);
            }
        }
        
        vector<vector<string>> result;
        for (auto it = mergedAccounts.begin(); it != mergedAccounts.end(); ++it) {
            vector<string> account;
            account.push_back(accounts[it->first][0]);
            for (auto &email : it->second) {
                account.push_back(email);
            }
            result.push_back(account);
        }
        
        return result;
    }
};
