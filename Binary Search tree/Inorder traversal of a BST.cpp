vector<int> inOrder(Node *root) {
    vector<int> result;
    stack<Node*> stack;
    Node* curr = root;

    while (curr != NULL || !stack.empty()) {
        while (curr != NULL) {
            stack.push(curr);
            curr = curr->left;
        }

        curr = stack.top();
        stack.pop();
        result.push_back(curr->data);

        curr = curr->right;
    }

    return result;
}
