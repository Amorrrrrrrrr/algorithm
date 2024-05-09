/* 单调栈 */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;                                                                          /* 栈的声明 */
        vector<int> ret(temperatures.size(), 0);
        st.push(0);
        for (int i = 1; i < temperatures.size(); i++) {                                         /* 遍历数组 */
            if (temperatures[i] <= temperatures[st.top()]) {                                    /* 单调栈的逻辑 */
                st.push(i);
            } else {
                while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                    ret[st.top()] = i - st.top();
                    st.pop();
                }
                st.push(i);
            }
        }
        return ret;
    }
};



/* 优化 */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> ret(temperatures.size(), 0);

        for (int i = 0; i < temperatures.size(); i++) {
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                ret[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ret;
    }
};

