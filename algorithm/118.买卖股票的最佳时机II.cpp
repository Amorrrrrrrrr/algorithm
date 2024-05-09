class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {                       /* 第 i 天的状态取决于第 i-1 天 */
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);     /* 股票可以买卖多次 */             
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);         
        }
        return dp[prices.size() - 1][0];
    }
};