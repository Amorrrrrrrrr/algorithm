/* 装满背包有多少种方法解法 */
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        if ((sum + target) % 2) return 0;
        if (sum < abs(target)) return 0;

        int targetNum = (sum + target) / 2;

        vector<int> dp(targetNum + 1);                          /* dp[j]: 装满容量为 j 的背包有 dp[j] 种方法 */
        dp[0] = 1;                                              /* 初始化：dp[0] 为 1，其他为 0 */
        for (int i = 0; i < nums.size(); i++) {
            for (int j = targetNum; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];                       /* 通用的递推公式 */
            }
        }
        return dp[targetNum];
    }
};