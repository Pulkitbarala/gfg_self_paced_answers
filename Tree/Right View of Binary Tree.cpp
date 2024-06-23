class Solution {
public:
    vector<int> rightView(Node *root) {
        vector<int> result;
        if (!root) return result;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                Node* current = q.front();
                q.pop();
                if (i == n - 1) result.push_back(current->data);
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }
        }
        return result;
    }
};
