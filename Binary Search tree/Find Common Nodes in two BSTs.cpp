void inorder(Node* root, vector<int>& res) {
    if (!root) return;
    inorder(root->left, res);
    res.push_back(root->data);
    inorder(root->right, res);
}
class Solution
{
    public:
    vector<int> findCommon(Node *root1, Node *root2)
    {
        vector<int> list1, list2, common;
        
        inorder(root1, list1);
        inorder(root2, list2);
        
        int i = 0, j = 0;
        while (i < list1.size() && j < list2.size()) {
            if (list1[i] < list2[j]) {
                i++;
            } else if (list1[i] > list2[j]) {
                j++;
            } else {
                common.push_back(list1[i]);
                i++;
                j++;
            }
        }
        
        return common;
    }
};