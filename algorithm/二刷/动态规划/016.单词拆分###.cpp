/* ��ȫ�������������� */
/* �ѵ����ڵ��ƹ�ʽ */
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size() + 1, INT_MAX - 1);
        dp[0] = 0;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {       
                string word = s.substr(j, i - j);
                if (wordSet.find(word) != wordSet.end()) {      /* ������Ʒ */
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[s.size()] == INT_MAX - 1 ? false : true;
    }
};


/* ��׼�� */
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