class Solution {
public:
    unordered_map<int, int> inorderMap;
    int postIndex;

    Node* buildTreeUtil(int inStart, int inEnd, int post[], int in[]) {
        if (inStart > inEnd) {
            return NULL;
        }

        int curr = post[postIndex--];
        Node* node = new Node(curr);

        if (inStart == inEnd) {
            return node;
        }

        int inIndex = inorderMap[curr];

        node->right = buildTreeUtil(inIndex + 1, inEnd, post, in);
        node->left = buildTreeUtil(inStart, inIndex - 1, post, in);

        return node;
    }

    Node* buildTree(int n, int in[], int post[]) {
        postIndex = n - 1;
        for (int i = 0; i < n; i++) {
            inorderMap[in[i]] = i;
        }
        return buildTreeUtil(0, n - 1, post, in);
    }
};