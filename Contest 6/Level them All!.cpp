int Count(Node *root, int L) {
    if (!root)
        return 0;
    
    int level_count = 0;
    int level = 1;
    queue<pair<Node*, int>> q;
    q.push({root, level});
    
    while (!q.empty()) {
        Node* node = q.front().first;
        int current_level = q.front().second;
        q.pop();
        
        if (current_level == L) {
            level_count += 1;
        }
        
        if (node->left) {
            q.push({node->left, current_level + 1});
        }
        
        if (node->right) {
            q.push({node->right, current_level + 1});
        }
        
        if (current_level > L) {
            break;
        }
    }
    
    return level_count;
}