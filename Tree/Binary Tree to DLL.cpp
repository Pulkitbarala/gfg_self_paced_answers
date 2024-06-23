class Solution
{
public: 
    Node *prev = NULL;
    Node *head = NULL;

    void bToDLLUtil(Node *root)
    {
        if (root == NULL)
            return;

        bToDLLUtil(root->left);

        if (prev == NULL) {
            head = root;
        } else {
            root->left = prev;
            prev->right = root;
        }
        prev = root;

        bToDLLUtil(root->right);
    }

    Node *bToDLL(Node *root)
    {
        bToDLLUtil(root);
        return head;
    }
};
