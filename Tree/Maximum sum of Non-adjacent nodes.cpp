class Solution {
public:
    int getMaxSum(Node* root) {
        auto result = getMaxSumHelper(root);
        return max(result.first, result.second);
    }

private:
    pair<int, int> getMaxSumHelper(Node* root) {
        if (root == nullptr) {
            return {0, 0};
        }

        auto left = getMaxSumHelper(root->left);
        auto right = getMaxSumHelper(root->right);

        int include = root->data + left.second + right.second;
        int exclude = max(left.first, left.second) + max(right.first, right.second);

        return {include, exclude};
    }
};