class Solution {
public:
    bool isBalanced(Node* root) {
        if (root == NULL) return true; 
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if (abs(leftHeight - rightHeight) > 1)
            return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    int height(Node* node) {
        if (node == NULL) return 0;
        return 1 + max(height(node->left), height(node->right));
    }
};