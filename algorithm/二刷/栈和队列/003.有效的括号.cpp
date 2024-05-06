class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(')');
            else if (s[i] == '[') st.push(']');
            else if (s[i] == '{') st.push('}');
            else {
                if (st.empty()) return false;
                else if (s[i] == st.top()) st.pop();
                else return false;
            }
        }

        return st.empty();
    }
};