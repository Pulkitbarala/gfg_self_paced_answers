class Solution
{
public:
    // Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // Lists to store uppercase and lowercase characters
        vector<char> upper, lower;

        // Separate the characters
        for (char c : str) {
            if (isupper(c)) {
                upper.push_back(c);
            } else {
                lower.push_back(c);
            }
        }

        // Sort both lists
        sort(upper.begin(), upper.end());
        sort(lower.begin(), lower.end());

        // Reconstruct the string
        int u = 0, l = 0;
        for (int i = 0; i < n; i++) {
            if (isupper(str[i])) {
                str[i] = upper[u++];
            } else {
                str[i] = lower[l++];
            }
        }

        return str;
    }
};