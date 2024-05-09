/* 编辑距离问题 */
class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));             /* dp[i][j]: 以 i - 1 为结尾 s 和有以 j - 1 为结尾的 t 的相同序列的个数为 dp[i][j] */          
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = dp[i][j - 1];                                           /* 相当于 t 要删除元素，t 如果把当前元素 t[j - 1] 删除，
                                                                                           那么dp[i][j] 的数值就是看 s[i - 1] 与 t[j - 2] 的比较结果了 */
            }
        }
        return dp[s.size()][t.size()] == s.size() ? true : false;
    }
};