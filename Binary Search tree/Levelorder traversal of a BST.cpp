vector<int> levelOrder(struct Node* node) {
    vector<int> result;
    if (node == NULL) return result;
    
    queue<Node*> q;
    q.push(node);
    
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        result.push_back(current->data);
        
        if (current->left != NULL) {
            q.push(current->left);
        }
        if (current->right != NULL) {
            q.push(current->right);
        }
    }
    
    return result;
}