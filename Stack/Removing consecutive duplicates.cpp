class Solution {
public:
    string removeConsecutiveDuplicates(string s) {
        stack<char> st;
        for (char ch : s) {
            if (st.empty() || st.top() != ch) {
                st.push(ch);
            }
        }
        
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};
