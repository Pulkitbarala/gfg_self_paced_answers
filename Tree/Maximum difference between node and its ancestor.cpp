int maxDiffUtil(Node* root, int& res)
{
    if (root == NULL)
        return INT_MAX;

    if (root->left == NULL && root->right == NULL)
        return root->data;

    int leftMin = maxDiffUtil(root->left, res);
    int rightMin = maxDiffUtil(root->right, res);

    int minDescendant = min(leftMin, rightMin);
    res = max(res, root->data - minDescendant);

    return min(root->data, minDescendant);
}

int maxDiff(Node* root)
{
    int res = INT_MIN;
    maxDiffUtil(root, res);
    return res;
}