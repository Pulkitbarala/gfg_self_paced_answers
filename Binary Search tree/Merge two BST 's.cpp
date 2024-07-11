class Solution {
public:
    void inorder(Node* root, vector<int>& result) {
        if (!root) return;
        inorder(root->left, result);
        result.push_back(root->data);
        inorder(root->right, result);
    }
    vector<int> mergeSortedVectors(vector<int>& v1, vector<int>& v2) {
        vector<int> merged;
        int i = 0, j = 0;
        while (i < v1.size() && j < v2.size()) {
            if (v1[i] < v2[j]) {
                merged.push_back(v1[i++]);
            } else {
                merged.push_back(v2[j++]);
            }
        }
        while (i < v1.size()) {
            merged.push_back(v1[i++]);
        }
        while (j < v2.size()) {
            merged.push_back(v2[j++]);
        }
        return merged;
    }

    vector<int> merge(Node* root1, Node* root2) {
        vector<int> result1, result2;
        inorder(root1, result1);
        inorder(root2, result2);
        return mergeSortedVectors(result1, result2);
    }
};
