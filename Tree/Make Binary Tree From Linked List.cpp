void convert(Node *head, TreeNode *&root) {
    if (!head) return;
    
    queue<TreeNode*> q;
    
    root = new TreeNode(head->data);
    q.push(root);
    
    Node* current = head->next;
    
    while (current) {
        TreeNode* parent = q.front();
        q.pop();
        
        TreeNode* leftChild = new TreeNode(current->data);
        q.push(leftChild);
        parent->left = leftChild;
        current = current->next;
        
        if (current) {
            TreeNode* rightChild = new TreeNode(current->data);
            q.push(rightChild);
            parent->right = rightChild;
            current = current->next;
        }
    }
}