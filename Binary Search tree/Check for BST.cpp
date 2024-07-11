class Solution {
public:
    void inorder(Node* root, vector<int>& nodes) {
        if (root == NULL) return;
        inorder(root->left, nodes);
        nodes.push_back(root->data);
        inorder(root->right, nodes);
    }
    bool isBST(Node* root) {
        vector<int> nodes;
        inorder(root, nodes);
        
        for (size_t i = 1; i < nodes.size(); ++i) {
            if (nodes[i] <= nodes[i-1]) {
                return false;
            }
        }
        return true;
    }
};
