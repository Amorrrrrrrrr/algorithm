/* 单调栈：找到当前元素右边/左边第一个比它大/小的元素是什么，找到这个元素的值或者下标之后再做其他的运算。
 * 实现：保证栈里面的元素是递增或者递减的。
 * - 从栈顶到栈底递增：求当前元素右边/左边第一个比它大的元素是什么
 * - 从栈顶到栈底递减：求当前元素右边/左边第一个比它小的元素是什么
 * 作用：存放/记录遍历过的元素，然后栈顶元素和当前遍历的元素做一个对比
 */

/* 栈里面放的是元素的下标 */
/* 从栈顶到栈底递增 */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> result(temperatures.size(), 0);
        st.push(0);
        for (int i = 1; i < temperatures.size(); i++) {
            if (temperatures[i] <= temperatures[st.top()]) {
                st.push(i);
            }
            else {
                while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                    result[st.top()] = i - st.top();
                    st.pop();
                }
                st.push(i);
            }
        }
        return result;
    }
};