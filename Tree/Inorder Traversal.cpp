class Solution {
  public:
vector<int> inOrder(Node* root) {
    vector<int> result;
    stack<Node*> s;
    Node* current = root;

    while (current != NULL || !s.empty()) {
        while (current != NULL) {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();
        result.push_back(current->data);

        current = current->right;
    }

    return result;
}

};