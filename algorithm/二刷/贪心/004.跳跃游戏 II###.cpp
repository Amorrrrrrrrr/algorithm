/* 贪心 */
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;

        int maxValue = nums[0];
        int tmp = maxValue;
        int ret = 1;
        for (int i = 0; i <= maxValue; i++) {
            if (maxValue >= nums.size() - 1) return ret;
            tmp = max(tmp, i + nums[i]);
            if (i == maxValue) {                            /* 遍历结束后更新最大值 */
                maxValue = tmp;
                ret++;
            }
        }

        return -1;
    }
};