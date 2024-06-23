bool areMirror(Node* a, Node* b) {
    if (a == NULL && b == NULL)
        return true;
    if (a == NULL || b == NULL)
        return false;
    return areMirror(a->left, b->right) && areMirror(a->right, b->left);
}

bool IsFoldable(Node* root) {
    if (root == NULL)
        return true;
    
    return areMirror(root->left, root->right);
}