class Solution {
public:
    int findMaxSum(Node* root) {
        int max_path_sum = INT_MIN;
        maxPathSum(root, max_path_sum);
        return max_path_sum;
    }

private:
    int maxPathSum(Node* node, int& max_path_sum) {
        if (node == NULL) {
            return 0;
        }
        int leftMaxPathSum = maxPathSum(node->left, max_path_sum);
        int rightMaxPathSum = maxPathSum(node->right, max_path_sum);
        int maxSumThroughNode = node->data + max(0, leftMaxPathSum) + max(0, rightMaxPathSum);
        max_path_sum = max(max_path_sum, maxSumThroughNode);
        return node->data + max(0, max(leftMaxPathSum, rightMaxPathSum));
    }
};