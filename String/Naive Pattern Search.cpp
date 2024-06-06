class Solution {
public:
    // Function to check if the given pattern exists in the given string or not.
    bool search(string pat, string txt) {
        int n = txt.length();
        int m = pat.length();

        // Iterate through the string using a loop that goes from 0 to n - m
        for (int i = 0; i <= n - m; i++) {
            int j;

            // Check if the pattern matches the substring starting at index i
            for (j = 0; j < m; j++) {
                if (txt[i + j] != pat[j]) {
                    break;
                }
            }

            // If the inner loop ran to completion, it means the pattern matches
            if (j == m) {
                return true;
            }
        }

        // If no match is found after the loop, return false
        return false;
    }
};
