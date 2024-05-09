class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (nums1.size() == 0) {
            nums1 = nums2;
            return;
        }
        if (nums2.size() == 0) return;

        int cur1 = m - 1;
        int cur2 = n - 1;
        
        int cur = nums1.size() - 1;
        while (cur1 >= 0 && cur2 >= 0) {
            if (nums2[cur2] >= nums1[cur1]) {
                nums1[cur] = nums2[cur2];
                cur--;
                cur2--;
            }
            else {
                nums1[cur] = nums1[cur1];
                cur--;
                cur1--;
            }
        }

        while (cur2 != -1) {
            nums1[cur] = nums2[cur2];
            cur--;
            cur2--;
        }

        return;
    }
};