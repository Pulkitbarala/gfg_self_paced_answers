class Solution {
public:
    int height(Node* node) {
        if (node == NULL) {
            return 0;
        }
        
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        
        return max(leftHeight, rightHeight) + 1;
    }
};
