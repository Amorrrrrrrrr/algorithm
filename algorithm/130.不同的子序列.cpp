/* 编辑距离问题 */
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<uint64_t>> dp(s.size() + 1, vector<uint64_t>(t.size() + 1, 0));           /* dp[i][j]: 以 i - 1 为结尾 s 中有以 j - 1 为结尾的 t 的个数为 dp[i][j] */
                                                                                                /* uint64_t：防止越界 */
        for (int j = 0; j <= t.size(); j++) {                                                   /* 初始化问题，比较特别（有意义的初始化） */
            dp[0][j] = 0;
        }
        for (int i = 0; i <= s.size(); i++) {
            dp[i][0] = 1;
        }
        dp[0][0] = 1;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];           /* 一部分是用 s[i - 1] 来匹配，那么个数为 dp[i - 1][j - 1]。
                                                                                                            （即不需要考虑当前 s 子串和 t 子串的最后一位字母，所以只需要 dp[i-1][j-1]。）
                                                                                                   一部分是不用 s[i - 1] 来匹配，个数为 dp[i - 1][j]。 
                                                                                                */
                else dp[i][j] = dp[i - 1][j];                                                   /* s 要删除元素 */
            }
        }
        return dp[s.size()][t.size()];
    }
};