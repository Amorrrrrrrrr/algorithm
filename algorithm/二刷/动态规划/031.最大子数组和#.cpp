class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MIN);
        dp[0] = nums[0];                                /* 注意初始化 */
        int ret = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);  /* 递推公式 */
            ret = max(dp[i], ret);
        }
        return ret;
    }
};