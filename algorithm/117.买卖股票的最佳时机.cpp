
class Solution {
public:
    int maxProfit(vector<int>& prices) {
                                                                        /* 用二维dp数组表示第 i 天的两种状态 
                                                                        * dp[i][0]: 持有这只股票我们所得到的最大的现金
                                                                        * dp[i][1]: 不持有这只股票我们所得到的最大的现金
                                                                        */
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {                       /* 第 i 天的状态取决于第 i-1 天 */
            dp[i][1] = max(dp[i - 1][1], -prices[i]);                   /* 股票只买卖一次 */  
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);         
        }
        return dp[prices.size() - 1][0];
                                               
    }
};