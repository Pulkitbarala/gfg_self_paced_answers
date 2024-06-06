class Solution
{
public:
    // Function to check if a string is an isogram or not.
    bool isIsogram(string s)
    {
        unordered_set<char> seen;

        for (char c : s)
        {
            // If the character is already present, return false
            if (seen.find(c) != seen.end())
            {
                return false;
            }

            // Add the character to the set
            seen.insert(c);
        }

        // If all characters are unique, return true
        return true;
    }
};