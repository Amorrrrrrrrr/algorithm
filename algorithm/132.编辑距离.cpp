/* 编辑距离问题 */
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));         /* dp[i][j]: 以 i-1 为尾的 word1 和以 j-1 为尾的 word2 相同的最少操作次数为 dp[i][j] */

        for (int i = 0; i <= word1.size(); i++) {                                           /* 有意义的初始化 */
            dp[i][0] = i;
        }
        for (int j = 0; j <= word2.size(); j++) {                                           
            dp[j][0] = j;
        }

        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else {
                    dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j  - 1] + 1), dp[i - 1][j - 1] + 1); /* 删除/替换（删除包括添加） */
                }
            }
        }

        return dp[word1.size()][word2.size()];
    }
};