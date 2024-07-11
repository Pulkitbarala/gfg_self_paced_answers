int floor(Node* root, int key) {
    int floorValue = -1;

    while (root != NULL) {
        if (root->data == key) {
            return root->data;
        } else if (root->data > key) {
            root = root->left;
        } else {
            floorValue = root->data;
            root = root->right;
        }
    }

    return floorValue;
}
