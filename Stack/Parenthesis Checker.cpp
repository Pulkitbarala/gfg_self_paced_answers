class Solution {
public:
    bool ispar(string x) {
        stack<char> s;
        for (char& ch : x) {
            if (ch == '(' || ch == '{' || ch == '[') {
                s.push(ch);
            } else {
                if (s.empty()) {
                    return false;
                }
                char top = s.top();
                if ((ch == ')' && top == '(') || 
                    (ch == '}' && top == '{') || 
                    (ch == ']' && top == '[')) {
                    s.pop();
                } else {
                    return false;
                }
            }
        }
        return s.empty();
    }
};