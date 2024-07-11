class Solution
{
    public:
        Node* insert(Node* root, int K) {
            if (root == NULL) {
                return new Node(K);
            }

            if (K < root->data) {
                root->left = insert(root->left, K);
            } else if (K > root->data) {
                root->right = insert(root->right, K);
            }

            return root;
        }
};
