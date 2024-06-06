class Solution
{
public:
    // Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Array to store frequency of each character
        int count[26] = {0};

        // Update the frequency of each character in the string
        for (char ch : str)
        {
            count[ch - 'a']++;
        }

        // Find the character with the maximum frequency
        int maxFreq = 0;
        char maxChar = 'a';
        for (int i = 0; i < 26; i++)
        {
            if (count[i] > maxFreq)
            {
                maxFreq = count[i];
                maxChar = 'a' + i;
            }
        }

        return maxChar;
    }
};
