class Solution {
public:
    int isSumProperty(Node *root) {
        if (!root) return 1;
        if (!root->left && !root->right) return 1;

        int left_data = (root->left) ? root->left->data : 0;
        int right_data = (root->right) ? root->right->data : 0;

        if (root->data == left_data + right_data) {
            return isSumProperty(root->left) && isSumProperty(root->right);
        } else {
            return 0;
        }
    }
};
