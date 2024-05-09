class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);                                 /* 以 i 为结尾的最大子数组的和 */
        dp[0] = nums[0];                                                /* 初始化 */
        int ret = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);                  /* 递推公式：延续前面/以当前节点重新开始 */
            if (ret < dp[i]) ret = dp[i];
        }

        return ret;                                                     /* 返回值需遍历 dp 数组 */
    }
};