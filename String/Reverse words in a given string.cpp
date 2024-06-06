class Solution {
public:
    // Function to reverse words in a given string.
    string reverseWords(string S) {
        int n = S.size();

        // Reverse the entire string
        reverse(S.begin(), S.end());

        // Initialize pointers for the beginning and end of each word
        int start = 0;
        int end = 0;

        // Iterate through the reversed string
        while (end < n) {
            // Find the end of the current word
            while (end < n && S[end] != '.') {
                end++;
            }

            // Reverse the current word
            reverse(S.begin() + start, S.begin() + end);

            // Move to the next word
            start = end + 1;
            end = start;
        }

        return S;
    }
};