class Solution
{
public:
    bool areRotations(string s1, string s2)
        if (s1.length() != s2.length())
        {
            return false;
        }
        string temp = s1 + s1;
        return (temp.find(s2) != string::npos);
    }
};