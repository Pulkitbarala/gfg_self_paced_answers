class Solution {
public:
    vector<int> serialize(Node *root) {
        vector<int> result;
        if (root == NULL) return result;

        queue<Node *> q;
        q.push(root);

        while (!q.empty()) {
            Node *curr = q.front();
            q.pop();

            if (curr == NULL) {
                result.push_back(-1);
            } else {
                result.push_back(curr->data);
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return result;
    }

    Node *deSerialize(vector<int> &data) {
        if (data.size() == 0) return NULL;

        Node *root = new Node(data[0]);
        queue<Node *> q;
        q.push(root);

        int i = 1;
        while (!q.empty()) {
            Node *curr = q.front();
            q.pop();

            if (data[i] != -1) {
                curr->left = new Node(data[i]);
                q.push(curr->left);
            }
            i++;

            if (data[i] != -1) {
                curr->right = new Node(data[i]);
                q.push(curr->right);
            }
            i++;
        }
        return root;
    }
};