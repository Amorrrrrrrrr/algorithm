class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;                                                                    /* 力扣修改了后台测试数据，需要用longlong */
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") { /* 二次分类，减少重复声明 */
                long long num1 = st.top();
                st.pop();
                long long num2 = st.top();
                st.pop();
                if (tokens[i] == "+") st.push(num2 + num1);
                if (tokens[i] == "-") st.push(num2 - num1);                                     /* num2 -// num1，先压入被除数/被减数，再压入除数/减数 */
                if (tokens[i] == "*") st.push(num2 * num1);
                if (tokens[i] == "/") st.push(num2 / num1);
            } else {
                st.push(stoll(tokens[i]));                                                      /* 字符串转换成整数 */
            }
        }

        int result = st.top();
        st.pop();                                                                               /* 把栈里最后一个元素弹出（其实不弹出也没事）*/
        return result;
    }
};