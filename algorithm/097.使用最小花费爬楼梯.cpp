/* 理解题意很关键 */
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1);                                    /* dp[i]: 到达 i 位置所需要的最小花费为 dp[i] */
        dp[0] = 0;                                                          /* 题意 */
        dp[1] = 0;

        for (int i = 2; i <= cost.size(); i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[cost.size()];                                             /* 题意：下标 cost.size() 才是楼顶 */
    }   
};