class Solution {
  public:
    Node* Bst(int pre[], int size) {
        if (size == 0) return NULL;
        
        Node* root = newNode(pre[0]);
        stack<Node*> s;
        s.push(root);
        
        for (int i = 1; i < size; ++i) {
            Node* temp = NULL;
            
            while (!s.empty() && pre[i] > s.top()->data) {
                temp = s.top();
                s.pop();
            }
            
            if (temp != NULL) {
                temp->right = newNode(pre[i]);
                s.push(temp->right);
            } else {
                s.top()->left = newNode(pre[i]);
                s.push(s.top()->left);
            }
        }
        
        return root;
    }
};
