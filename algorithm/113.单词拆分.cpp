/* ��ȫ���� + ������ */
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> mySet(wordDict.begin(), wordDict.end());

        vector<bool> dp(s.size() + 1, false);                               /* dp[i]: ����Ϊ i ���ַ����Ƿ������ֵ��еĵ������ */
        dp[0] = true;                                                       /* ��ʼ�� */
        for (int i = 0; i <= s.size(); i++) {                               /* �������� */
            for (int j = 0; j < i; j++) {                                   /* ������Ʒ */
                string str = s.substr(j, i - j);                            /* substr(��ʼλ�ã���ȡ�ĸ���) */
                if (mySet.find(str) != mySet.end() && dp[j] == true) {      /* ���ƹ�ʽ */
                    dp[i] = true;
                }
            }
        }
        return dp[s.size()];
    }
};