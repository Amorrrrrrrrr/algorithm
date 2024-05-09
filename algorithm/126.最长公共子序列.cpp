class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));     /* dp[i][j]: 以 [0,i-1] 的 text1 和 以 [0,j-1] 的 text2 
                                                                                           这两个数组的最长公共子序列的长度 
                                                                                        */
        
        for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);                         /* 不相等时的递推公式 */
                }
            }
        }
        return dp[text1.size()][text2.size()];                                          /* 直接返回二维数组的最后一个元素即可 */
    }
};