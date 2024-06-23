int subtreeSum(Node* root, int X, int& count) {
    if (root == NULL) {
        return 0;
    }

    int leftSum = subtreeSum(root->left, X, count);
    int rightSum = subtreeSum(root->right, X, count);

    int totalSum = root->data + leftSum + rightSum;

    if (totalSum == X) {
        count++;
    }

    return totalSum;
}
int countSubtreesWithSumX(Node* root, int X)
{
    int count = 0;
    subtreeSum(root, X, count);
    return count;
}