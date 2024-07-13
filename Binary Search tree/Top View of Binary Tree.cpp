class Solution {
public:
    vector<int> topView(Node *root) {
        vector<int> result;
        if (!root) return result;

        map<int, int> topNode;
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto p = q.front();
            Node* node = p.first;
            int hd = p.second;
            q.pop();

            if (topNode.find(hd) == topNode.end()) {
                topNode[hd] = node->data;
            }

            if (node->left) {
                q.push({node->left, hd - 1});
            }
            if (node->right) {
                q.push({node->right, hd + 1});
            }
        }

        for (auto it : topNode) {
            result.push_back(it.second);
        }

        return result;
    }
};
