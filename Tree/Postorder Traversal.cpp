vector<int> postOrder(Node* root) {
    vector<int> result;
    if (!root) return result;

    stack<Node*> nodeStack;
    Node* current = root;
    Node* lastVisited = nullptr;

    while (!nodeStack.empty() || current) {
        if (current) {
            nodeStack.push(current);
            current = current->left;
        } else {
            Node* peekNode = nodeStack.top();
            if (peekNode->right && lastVisited != peekNode->right) {
                current = peekNode->right;
            } else {
                result.push_back(peekNode->data);
                lastVisited = nodeStack.top();
                nodeStack.pop();
            }
        }
    }

    return result;
}
