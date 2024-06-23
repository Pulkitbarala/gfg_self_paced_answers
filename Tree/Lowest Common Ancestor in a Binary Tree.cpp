class Solution {
public:
    Node* lca(Node* root, int n1, int n2) {
        if (root == NULL || root->data == n1 || root->data == n2) {
            return root;
        }
        Node* left_lca = lca(root->left, n1, n2);
        Node* right_lca = lca(root->right, n1, n2);
        if (left_lca && right_lca) {
            return root;
        }
        return (left_lca != NULL) ? left_lca : right_lca;
    }
};