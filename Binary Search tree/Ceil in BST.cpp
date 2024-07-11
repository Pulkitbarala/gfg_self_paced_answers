int findCeil(Node* root, int input) {
    int ceilValue = -1;

    while (root != NULL) {
        if (root->data == input) {
            return root->data;
        } else if (root->data < input) {
            root = root->right;
        } else {
            ceilValue = root->data;
            root = root->left;
        }
    }

    return ceilValue;
}
