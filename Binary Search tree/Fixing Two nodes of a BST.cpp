class Solution {
public:
    Node* first;
    Node* middle;
    Node* last;
    Node* prev;

    Solution() {
        first = middle = last = prev = NULL;
    }

    void correctBST(Node* root) {
        inorder(root);

        if (first && last) {
            swap(first->data, last->data);
        } else if (first && middle) {
            swap(first->data, middle->data);
        }
    }

    void inorder(Node* root) {
        if (!root) return;

        inorder(root->left);

        if (prev && root->data < prev->data) {
            if (!first) {
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }

        prev = root;

        inorder(root->right);
    }
};
