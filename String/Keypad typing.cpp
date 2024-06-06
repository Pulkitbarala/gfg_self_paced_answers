string printNumber(string s, int n) 
{
    // Mapping between characters and their corresponding digits on the keypad
    unordered_map<char, string> keypad = {
        {'a', "2"}, {'b', "2"}, {'c', "2"},
        {'d', "3"}, {'e', "3"}, {'f', "3"},
        {'g', "4"}, {'h', "4"}, {'i', "4"},
        {'j', "5"}, {'k', "5"}, {'l', "5"},
        {'m', "6"}, {'n', "6"}, {'o', "6"},
        {'p', "7"}, {'q', "7"}, {'r', "7"}, {'s', "7"},
        {'t', "8"}, {'u', "8"}, {'v', "8"},
        {'w', "9"}, {'x', "9"}, {'y', "9"}, {'z', "9"}
    };
    
    string result;
    // Iterate through the given string and replace each character with its corresponding digit
    for(int i = 0; i < n; i++) {
        char ch = s[i];
        result += keypad[ch];
    }
    
    return result;
}
