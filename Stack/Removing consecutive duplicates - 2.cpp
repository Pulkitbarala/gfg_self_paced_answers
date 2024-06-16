class Solution {
public:
    string removePair(string str) {
        stack<char> st;
        for (char ch : str) {
            if (!st.empty() && st.top() == ch) {
                st.pop();
            } else {
                st.push(ch);
            }
        }
        
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        
        reverse(result.begin(), result.end());
        return result.empty() ? "Empty String" : result;
    }
};