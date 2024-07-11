Node* constructBst(int arr[], int n) {
    if (n == 0) return NULL;

    Node* root = new Node(arr[0]);
    queue<pair<Node*, pair<int, int>>> q;
    q.push({root, {INT_MIN, INT_MAX}});

    int i = 1;
    while (i < n) {
        auto temp = q.front();
        q.pop();
        
        Node* node = temp.first;
        int min = temp.second.first;
        int max = temp.second.second;
        
        if (i < n && arr[i] > min && arr[i] < node->data) {
            node->left = new Node(arr[i]);
            q.push({node->left, {min, node->data}});
            i++;
        }
        
        if (i < n && arr[i] > node->data && arr[i] < max) {
            node->right = new Node(arr[i]);
            q.push({node->right, {node->data, max}});
            i++;
        }
    }
    
    return root;
}
