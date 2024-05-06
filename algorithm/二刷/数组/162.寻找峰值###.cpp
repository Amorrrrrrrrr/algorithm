/* 二分查找法 + 贪心 */
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        int left = 0;
        int right = n - 1;
        while (left < right) {                                  /* 当 l = r 时，即找到峰值 */
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid + 1]) left = mid + 1;      /* 因为 mid 是通过向下取整计算得到的，在 l < r 的情况下肯定会存在右邻居 */
            else right = mid;
        }

        return left;
    }
};