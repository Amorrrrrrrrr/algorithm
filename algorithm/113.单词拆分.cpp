/* 完全背包 + 排列数 */
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> mySet(wordDict.begin(), wordDict.end());

        vector<bool> dp(s.size() + 1, false);                               /* dp[i]: 长度为 i 的字符串是否能由字典中的单词组成 */
        dp[0] = true;                                                       /* 初始化 */
        for (int i = 0; i <= s.size(); i++) {                               /* 遍历背包 */
            for (int j = 0; j < i; j++) {                                   /* 遍历物品 */
                string str = s.substr(j, i - j);                            /* substr(起始位置，截取的个数) */
                if (mySet.find(str) != mySet.end() && dp[j] == true) {      /* 递推公式 */
                    dp[i] = true;
                }
            }
        }
        return dp[s.size()];
    }
};