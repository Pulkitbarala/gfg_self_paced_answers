class Solution {
public:
    // Function to find the minimum indexed character.
    int minIndexChar(string str, string patt) {
        unordered_map<char, int> indices;

        // Store the indices of characters in str
        for (int i = 0; i < str.length(); i++) {
            if (indices.find(str[i]) == indices.end()) {
                indices[str[i]] = i;
            }
        }

        int minIndex = INT_MAX;

        // Iterate through the characters in patt and find the minimum index
        for (char c : patt) {
            if (indices.find(c) != indices.end()) {
                minIndex = min(minIndex, indices[c]);
            }
        }

        // If no character in patt is found in str, return -1
        if (minIndex == INT_MAX) {
            return -1;
        }

        return minIndex;
    }
};