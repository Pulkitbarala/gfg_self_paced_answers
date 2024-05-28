//User function Template for C++

class Solution
{
public:
    vector<string> possibleWords(int a[], int N)
    {
        vector<string> keypad = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        vector<string> result;
        function<void(int, string)> backtrack = [&](int index, string current) {
            if (index == N) {
                result.push_back(current);
                return;
            }
            string letters = keypad[a[index]];
            for (char ch : letters) {
                backtrack(index + 1, current + ch);
            }
        };
        backtrack(0, "");
        return result;
    }
};