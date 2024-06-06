class Solution
{
public:
    // Function to find the index of the first repeating character from the left.
    int repeatedCharacter(string s)
    {
        int n = s.length();
 
    // Consider each character
    for (int i = 0; i < n; i++) {
 
        // Check if this character appears again
        for (int j = i + 1; j < n; j++) {
 
            if (s[i] == s[j]) {
                return i;
            }
        }
    }
 
    // If no repeating character found
    return -1;
}
};