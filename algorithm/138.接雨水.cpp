/* 单调栈是按照行方向来计算雨水 */
class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        if (height.size() == 0) return result;

        stack<int> st;
        st.push(0);
        for (int i = 1; i < height.size(); i++) {
            if (height[i] < height[st.top()]) st.push(i);
            else if (height[i] == height[st.top()]) {
                st.pop();                                                           /* 注意（可 pop 可不 pop） */
                st.push(i);
            }
            else {
                while(!st.empty() && height[i] > height[st.top()]) {                /* 计算凹槽雨水的逻辑：栈顶和栈顶的下一个元素以及要入栈的元素，三个元素来接水 */
                    int mid = st.top();st.pop();
                    if (!st.empty()) {
                        int h = min(height[i], height[st.top()]) - height[mid];
                        int w = i - st.top() - 1;
                        result += h * w;
                    }
                }
                st.push(i);
            }
        }
        return result;
    }
};