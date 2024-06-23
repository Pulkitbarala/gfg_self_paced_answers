class Solution {
  public:
    int getMaxWidth(Node* root) {
        if (!root) return 0;
        
        queue<Node*> q;
        q.push(root);
        int maxWidth = 0;
        
        while (!q.empty()) {
            int count = q.size();
            maxWidth = max(maxWidth, count);
            for (int i = 0; i < count; i++) {
                Node* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        
        return maxWidth;
    }
};