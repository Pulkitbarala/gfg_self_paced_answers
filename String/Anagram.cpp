class Solution
{
public:
    // Function to check whether two strings are anagrams of each other.
    bool isAnagram(string a, string b)
    {
        // If lengths of strings are not equal, they can't be anagrams
        if (a.length() != b.length()) {
            return false;
        }
        
        // Array to store frequency of each character
        int count[26] = {0};
        
        // Update frequency of characters in string 'a'
        for (char c : a) {
            count[c - 'a']++;
        }
        
        // Update frequency of characters in string 'b'
        for (char c : b) {
            count[c - 'a']--;
        }
        
        // If all frequencies are zero, the strings are anagrams
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return false;
            }
        }
        
        return true;
    }
};