/* 单调栈处理 nums2，result 收集 nums1 */
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result(nums1.size(), -1);
        if (nums1.size() == 0) return result;

        unordered_map<int, int> umap;
        for (int i = 0; i < nums1.size(); i++) {                                /* 哈希映射：根据元素的数值可以找到其对应的下标 */
            umap[nums1[i]] = i;
        }

        stack<int> st;
        st.push(0);
        for (int j = 1; j < nums2.size(); j++) {
            if (nums2[j] <= nums2[st.top()]) st.push(j);
            else {
                while (!st.empty() && nums2[j] > nums2[st.top()]) {
                    if (umap.find(nums2[st.top()]) != umap.end()) {             /* nums2 到 nums1 的映射 */
                        result[umap[nums2[st.top()]]] = nums2[j];
                    }
                    st.pop();
                }
                st.push(j);
            }
        }
        return result;

    }
};