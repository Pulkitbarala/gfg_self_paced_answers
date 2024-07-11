class Solution
{
public:
    int minDiff(Node *root, int K)
    {
        int minDiff = INT_MAX;

        while (root != NULL) {
            minDiff = min(minDiff, abs(root->data - K));
            
            if (K < root->data) {
                root = root->left;
            } else if (K > root->data) {
                root = root->right;
            } else {
                break;
            }
        }

        return minDiff;
    }
};
