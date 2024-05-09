class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        st.push(0);
        vector<int> ret(nums.size(), -1);
        int k = nums.size();
        for (int i = 1; i < 2 * nums.size(); i++) {
            if (nums[i % k] <= nums[st.top()]) {
                st.push(i % k);
            } else {
                while (!st.empty() &&  nums[i % k] > nums[st.top()]) {
                    ret[st.top()] = nums[i % k];
                    st.pop();
                }
                st.push(i % k);
            }
        }
        return ret;
    }
};