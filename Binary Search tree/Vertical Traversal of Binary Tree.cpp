class Solution {
public:
    vector<int> verticalOrder(Node* root) {
        vector<int> result;
        if (!root) return result;

        map<int, vector<int>> nodesMap;
        queue<pair<Node*, int>> q;
        q.push(make_pair(root, 0));

        while (!q.empty()) {
            pair<Node*, int> temp = q.front();
            q.pop();
            Node* node = temp.first;
            int hd = temp.second;
            nodesMap[hd].push_back(node->data);

            if (node->left) {
                q.push(make_pair(node->left, hd - 1));
            }
            if (node->right) {
                q.push(make_pair(node->right, hd + 1));
            }
        }

        for (auto it : nodesMap) {
            for (int data : it.second) {
                result.push_back(data);
            }
        }

        return result;
    }
};