/* 首尾相连或者是成环的这类题目都可以用取模的方式处理 */
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> result(nums.size(), -1);
        if (nums.size() == 0) return result;

        stack<int> st;
        st.push(0);
        for (int i = 1; i <= 2 * nums.size() - 1; i++) {                            /* 用取模的方式来模拟转圈的过程 */
            if (nums[i % nums.size()] <= nums[st.top()]) st.push(i % nums.size());
            else {
                while (!st.empty() && nums[i % nums.size()] > nums[st.top()]) {
                    result[st.top()] = nums[i % nums.size()];                       /* 不会产生覆盖问题，错误的结果会留在单调栈中 */
                    st.pop();
                }
                st.push(i % nums.size());
            }
        }
        return result;

    }
};