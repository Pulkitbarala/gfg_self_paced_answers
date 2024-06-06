class Solution {
public:
    // Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S) {
        unordered_map<char, int> freq;

        // Count the frequency of each character
        for (char c : S) {
            freq[c]++;
        }

        // Find the first non-repeating character
        for (char c : S) {
            if (freq[c] == 1) {
                return c;
            }
        }

        // If no non-repeating character found, return '$'
        return '$';
    }
};