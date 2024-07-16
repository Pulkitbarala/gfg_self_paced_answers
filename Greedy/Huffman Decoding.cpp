class Solution {
  public:
    string decodeHuffmanData(struct MinHeapNode* root, string binaryString) {
        string result = "";
        MinHeapNode* current = root;

        for (char bit : binaryString) {
            if (bit == '0') {
                current = current->left;
            } else {
                current = current->right;
            }

            // If leaf node is reached
            if (current->left == NULL && current->right == NULL) {
                result += current->data;
                current = root;
            }
        }
        return result;
    }
};