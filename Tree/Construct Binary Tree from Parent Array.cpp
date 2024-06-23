class Solution{
  public:
    Node *createTree(int parent[], int N)
    {
        vector<Node*> nodes(N, nullptr);
        Node* root = nullptr;
        for (int i = 0; i < N; ++i) {
            nodes[i] = new Node(i);
        }
        for (int i = 0; i < N; ++i) {
            if (parent[i] == -1) {
                root = nodes[i];
            } else {
                if (!nodes[parent[i]]->left) {
                    nodes[parent[i]]->left = nodes[i];
                } else {
                    nodes[parent[i]]->right = nodes[i];
                }
            }
        }
        
        return root;
    }
};