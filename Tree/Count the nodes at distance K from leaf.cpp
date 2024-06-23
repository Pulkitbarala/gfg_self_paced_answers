class Solution {
    void countSpecialNodes(Node* node, int k, vector<Node*>& path, unordered_set<Node*>& specialNodes) {
        if (node == NULL) return;

        path.push_back(node);

        if (node->left == NULL && node->right == NULL) {
            int path_len = path.size();
            if (path_len >= k + 1) {
                specialNodes.insert(path[path_len - k - 1]);
            }
        }

        countSpecialNodes(node->left, k, path, specialNodes);
        countSpecialNodes(node->right, k, path, specialNodes);

        path.pop_back();
    }

public:
    int printKDistantfromLeaf(Node* root, int k) {
        vector<Node*> path;
        unordered_set<Node*> specialNodes;
        countSpecialNodes(root, k, path, specialNodes);
        return specialNodes.size();
    }
};