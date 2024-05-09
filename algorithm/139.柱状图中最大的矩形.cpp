class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int result = 0;
        if (heights.size() == 0) return result;

        heights.insert(heights.begin(), 0);                                 /* 在 height 数组前后各加一个元素0
                                                                             * - 末尾0：让栈里的所有元素，走到情况三的逻辑
                                                                             * - 开头0：为了避免空栈取值，直接跳过了计算结果的逻辑
                                                                             */
        heights.push_back(0);
        stack<int> st;
        st.push(0);
        for (int i = 1; i < heights.size(); i++) {
            if (heights[i] > heights[st.top()]) st.push(i);
            else if (heights[i] == heights[st.top()]) {
                st.pop();
                st.push(i);
            }
            else {
                while (!st.empty() && heights[i] < heights[st.top()]) {     /* 计算矩形面积的逻辑：栈顶和栈顶的下一个元素以及要入栈的三个元素组成了我们要求最大面积的高度和宽度 */
                    int mid = st.top();st.pop();
                    if (!st.empty()) {
                        int h = heights[mid];
                        int w = i - st.top() - 1;
                        result = max(result, h * w);
                    }
                }
                st.push(i);
            }

        }
        return result;
    }
};