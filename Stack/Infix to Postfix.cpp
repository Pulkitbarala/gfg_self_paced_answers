class Solution {
public:
    int precedence(char c) {
        if (c == '^')
            return 3;
        else if (c == '*' || c == '/')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return -1;
    }
    
    string infixToPostfix(string s) {
        stack<char> st;
        string postfix;
        
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            
            if (isalnum(c))
                postfix += c;
            else if (c == '(')
                st.push('(');
            else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    postfix += st.top();
                    st.pop();
                }
                st.pop();
            }
            else {
                while (!st.empty() && precedence(st.top()) >= precedence(c)) {
                    postfix += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        
        while (!st.empty()) {
            postfix += st.top();
            st.pop();
        }
        
        return postfix;
    }
};