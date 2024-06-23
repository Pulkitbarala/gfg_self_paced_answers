class Solution
{
public:
    void connect(Node *root)
    {
        if (!root) return;
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            Node* prev = nullptr;
            
            while (size--) {
                Node* curr = q.front();
                q.pop();
                
                if (prev) {
                    prev->nextRight = curr;
                }
                prev = curr;
                
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            prev->nextRight = nullptr;
        }
    }
};
