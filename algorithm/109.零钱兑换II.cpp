/* 完全背包+组合数 */
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);                      /* dp[j]: 装满容量为 j 的背包一共有 dp[j] 种方法 */
        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};