class Solution {
  public:
    vector<int> printNearNodes(Node *root, int low, int high) {
        vector<int> result;
        inOrderTraversal(root, low, high, result);
        return result;
    }

  private:
    void inOrderTraversal(Node* node, int low, int high, vector<int>& result) {
        if (!node) return;

        if (node->data > low) {
            inOrderTraversal(node->left, low, high, result);
        }

        if (node->data >= low && node->data <= high) {
            result.push_back(node->data);
        }

        if (node->data < high) {
            inOrderTraversal(node->right, low, high, result);
        }
    }
};