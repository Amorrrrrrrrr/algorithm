class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int ret = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {               /* 遍历条件 */
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);      /* 递推公式 */
                    ret = max(dp[i], ret);
                }
            }
        }
        return ret;                                     /* 返回结果 */
    }
};

/* 子序列与子数组问题
 * 最长递增子序列 与 最长递增子数组问题
 * 最长公共子序列 与 最长公共子数组问题
 * 回文子串的个数 与 最长回文子序列
 */

/* 子数组的条件更严苛 */