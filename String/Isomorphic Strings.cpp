class Solution
{
    public:
    // Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        // If lengths of two strings are not equal, they cannot be isomorphic
        if (str1.length() != str2.length()) {
            return false;
        }
        
        // Create two maps to store the mapping of characters
        unordered_map<char, char> map1;
        unordered_map<char, char> map2;
        
        for (int i = 0; i < str1.length(); i++) {
            char c1 = str1[i];
            char c2 = str2[i];
            
            // If c1 has been seen before
            if (map1.find(c1) != map1.end()) {
                // If the previous mapping does not match current character of str2
                if (map1[c1] != c2) {
                    return false;
                }
            } else {
                map1[c1] = c2;
            }
            
            // If c2 has been seen before
            if (map2.find(c2) != map2.end()) {
                // If the previous mapping does not match current character of str1
                if (map2[c2] != c1) {
                    return false;
                }
            } else {
                map2[c2] = c1;
            }
        }
        
        return true;
    }
};