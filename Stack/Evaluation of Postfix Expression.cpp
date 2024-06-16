class Solution {
public:
    int evaluatePostfix(string S) {
        stack<int> st;
        
        for (char c : S) {
            if (isdigit(c)) {
                st.push(c - '0');
            } else {
                int operand2 = st.top();
                st.pop();
                int operand1 = st.top();
                st.pop();
                
                int result;
                switch(c) {
                    case '+': result = operand1 + operand2; break;
                    case '-': result = operand1 - operand2; break;
                    case '*': result = operand1 * operand2; break;
                    case '/': result = operand1 / operand2; break;
                }
                
                st.push(result);
            }
        }
        
        return st.top();
    }
};