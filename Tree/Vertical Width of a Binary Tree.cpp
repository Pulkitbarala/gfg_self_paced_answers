int verticalWidth(Node* root) {
    if (root == NULL) {
        return 0;
    }
    
    set<int> horizontalDistances;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    
    while (!q.empty()) {
        auto current = q.front();
        q.pop();
        Node* node = current.first;
        int horizontalDistance = current.second;
        
        horizontalDistances.insert(horizontalDistance);
        
        if (node->left != NULL) {
            q.push({node->left, horizontalDistance - 1});
        }
        
        if (node->right != NULL) {
            q.push({node->right, horizontalDistance + 1});
        }
    }
    
    return horizontalDistances.size();
}