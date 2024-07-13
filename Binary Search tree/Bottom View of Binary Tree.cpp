class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> result;
        if (!root) return result;
        map<int, int> hdNodeMap;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            Node* node = p.first;
            int hd = p.second;
            hdNodeMap[hd] = node->data;
            if (node->left)
                q.push({node->left, hd - 1});
            if (node->right)
                q.push({node->right, hd + 1});
        }
        for (auto it : hdNodeMap) {
            result.push_back(it.second);
        }
        return result;
    }
};
