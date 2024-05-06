/* 完全背包求排列问题 */
/* 难点在于递推公式 */
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size() + 1, INT_MAX - 1);
        dp[0] = 0;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {       
                string word = s.substr(j, i - j);
                if (wordSet.find(word) != wordSet.end()) {      /* 遍历物品 */
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[s.size()] == INT_MAX - 1 ? false : true;
    }
};


/* 标准答案 */
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> uset(wordDict.begin(), wordDict.end());

        vector<int> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                string word = s.substr(j, i - j);
                if (uset.find(word) != uset.end() && dp[j]) {
                    dp[i] = dp[j];
                }
            }
        }

        return dp[s.size()];
    }
};