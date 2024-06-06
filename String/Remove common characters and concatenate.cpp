class Solution {
public:
    // Function to remove common characters and concatenate two strings.
    string concatenatedString(string s1, string s2) {
        unordered_set<char> s1_set, s2_set;

        // Add characters of s1 to s1_set
        for (char c : s1) {
            s1_set.insert(c);
        }

        // Add characters of s2 to s2_set
        for (char c : s2) {
            s2_set.insert(c);
        }

        // Remove common characters from s1 and s2
        for (int i = 0; i < s1.size(); ++i) {
            if (s2_set.find(s1[i]) != s2_set.end()) {
                s1.erase(i, 1);
                --i; // adjust index after removal
            }
        }

        for (int i = 0; i < s2.size(); ++i) {
            if (s1_set.find(s2[i]) != s1_set.end()) {
                s2.erase(i, 1);
                --i; // adjust index after removal
            }
        }

        // Concatenate modified s1 and s2
        string result = s1 + s2;

        // If result string is empty, return -1
        if (result.empty()) {
            return "-1";
        }

        return result;
    }
};