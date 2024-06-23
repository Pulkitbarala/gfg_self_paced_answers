vector<int> preorder(Node* root) {
    vector<int> result;
    if (root == NULL) {
        return result;
    }
    
    stack<Node*> s;
    s.push(root);
    
    while (!s.empty()) {
        Node* current = s.top();
        s.pop();
        result.push_back(current->data);
        
        if (current->right) {
            s.push(current->right);
        }
        if (current->left) {
            s.push(current->left);
        }
    }
    
    return result;
}
