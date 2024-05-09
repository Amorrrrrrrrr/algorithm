class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(')');                           /* 添加另半边括号，便于后续匹配 */
            } 
            else if (s[i] == '[') {
                st.push(']');
            }
            else if (s[i] == '{') {
                st.push('}');
            }
            else {
                if (st.empty() || st.top() != s[i]) {    /* 考虑不匹配和缺少左括号情况 */
                    return false;
                } 
                else {
                    st.pop();                            /* 匹配成功情况 */
                }
            }
        }
        return st.empty();                               /* 考虑缺少右括号情况 */
    }
};