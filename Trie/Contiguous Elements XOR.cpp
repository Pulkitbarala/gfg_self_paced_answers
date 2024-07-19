struct TrieNode {
    TrieNode *children[2];
    TrieNode() {
        children[0] = children[1] = nullptr;
    }
};
class Solution {
public:
    void insertTrie(TrieNode *root, int num) {
        TrieNode *node = root;
        for (int i = INT_SIZE - 1; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (!node->children[bit]) {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
        }
    }
    int findMaxXOR(TrieNode *root, int num) {
        TrieNode *node = root;
        int maxXOR = 0;
        for (int i = INT_SIZE - 1; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (node->children[1 - bit]) {
                maxXOR = (maxXOR << 1) | 1;
                node = node->children[1 - bit];
            } else {
                maxXOR = (maxXOR << 1);
                node = node->children[bit];
            }
        }
        return maxXOR;
    }
    int maxSubarrayXOR(int arr[], int n) {
        TrieNode *root = new TrieNode();
        int prefixXor = 0;
        int maxXOR = INT_MIN;
        insertTrie(root, 0);

        for (int i = 0; i < n; ++i) {
            prefixXor ^= arr[i];
            insertTrie(root, prefixXor);
            maxXOR = max(maxXOR, findMaxXOR(root, prefixXor));
        }

        return maxXOR;
    }
};