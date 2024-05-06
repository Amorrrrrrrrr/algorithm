/* 先取反负数最小值，再循环取反非负数最小值 */

class Solution {
    static bool cmp(int a, int b) {                                 /* 比较函数 */
        return abs(a) > abs(b);
    }

public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp);                        /* 按照绝对值从大到小排序 */
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0 && k > 0) {
                nums[i] = -nums[i];
                k--;
            }
        }
        if (k % 2 == 1) nums[nums.size() - 1] *= -1;                /* 用判断代替--，提高效率 */

        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            result += nums[i];
        }

        return result;
    }
};