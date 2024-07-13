class Solution {
  public:
    int minValue(Node* root) {
        if (root == NULL) {
            return -1;
        }
        
        Node* current = root;
        while (current->left != NULL) {
            current = current->left;
        }
        return current->data;
    }
};
