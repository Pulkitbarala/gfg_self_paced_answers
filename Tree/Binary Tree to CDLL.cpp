class Solution {
public:
    Node* bTreeToCList(Node *root) {
        if (!root) return nullptr;

        Node *head = nullptr, *prev = nullptr;
        convertToCDLL(root, head, prev);

        head->left = prev;
        prev->right = head;

        return head;
    }

private:
    void convertToCDLL(Node* root, Node*& head, Node*& prev) {
        if (!root) return;

        convertToCDLL(root->left, head, prev);

        if (prev == nullptr) {
            head = root; 
        } else {
            root->left = prev;
            prev->right = root;
        }
        prev = root;
        convertToCDLL(root->right, head, prev);
    }
};
