void collectLeafNodes(Node *root, vector<int> &leaves) {
    if (root == nullptr) return;
    if (root->left == nullptr && root->right == nullptr) {
        leaves.push_back(root->data);
        return;
    }
    collectLeafNodes(root->left, leaves);
    collectLeafNodes(root->right, leaves);
}
int leafSumAlternate(Node *root) {
    vector<int> leaves;
    collectLeafNodes(root, leaves);

    int sum = 0;
    for (size_t i = 0; i < leaves.size(); i += 2) {
        sum += leaves[i];
    }
    return sum;
}