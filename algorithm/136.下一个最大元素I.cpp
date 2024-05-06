/* ����ջ���� nums2��result �ռ� nums1 */
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result(nums1.size(), -1);
        if (nums1.size() == 0) return result;

        unordered_map<int, int> umap;
        for (int i = 0; i < nums1.size(); i++) {                                /* ��ϣӳ�䣺����Ԫ�ص���ֵ�����ҵ����Ӧ���±� */
            umap[nums1[i]] = i;
        }

        stack<int> st;
        st.push(0);
        for (int j = 1; j < nums2.size(); j++) {
            if (nums2[j] <= nums2[st.top()]) st.push(j);
            else {
                while (!st.empty() && nums2[j] > nums2[st.top()]) {
                    if (umap.find(nums2[st.top()]) != umap.end()) {             /* nums2 �� nums1 ��ӳ�� */
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