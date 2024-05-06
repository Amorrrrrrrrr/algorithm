/* 完全背包 */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX - 1);                    /* dp[j]: 装满容量为 j 的背包最少物品为 dp[j] */
        dp[0] = 0;                                                  /* 初始化 */
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }

        return dp[amount] == (INT_MAX - 1) ? -1 : dp[amount];
    }
};



/* 标准答案 */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                if (dp[j - coins[i]] != INT_MAX) {                  /* 如果dp[j - coins[i]]是初始值则跳过 */
                    dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
                }
            }
        }
        if (dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};