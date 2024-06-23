class Solution {
public:
    vector<int> zigZagTraversal(Node* root) {
        vector<int> result;
        if (!root) return result;

        deque<Node*> dq;
        dq.push_back(root);
        bool leftToRight = true;

        while (!dq.empty()) {
            int levelSize = dq.size();
            vector<int> currentLevel(levelSize);

            for (int i = 0; i < levelSize; ++i) {
                Node* node;
                if (leftToRight) {
                    node = dq.front();
                    dq.pop_front();
                    if (node->left) dq.push_back(node->left);
                    if (node->right) dq.push_back(node->right);
                } else {
                    node = dq.back();
                    dq.pop_back();
                    if (node->right) dq.push_front(node->right);
                    if (node->left) dq.push_front(node->left);
                }
                currentLevel[i] = node->data;
            }
            result.insert(result.end(), currentLevel.begin(), currentLevel.end());
            leftToRight = !leftToRight;
        }
        return result;
    }
};
