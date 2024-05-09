/* 动态规划 */
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(2, 1));                 /* 第 i 个元素作为山顶/山谷时的最长摆动序列为 dp[i][0]/dp[i][1] */
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) dp[i][0] = max(dp[i][0], dp[j][1] + 1);
            }
            for (int j = 0; j < i; j++) {
                if (nums[j] > nums[i]) dp[i][1] = max(dp[i][1], dp[j][0] + 1);
            }
        }
        return max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
    }
};