class Solution {
public:
    int countSubstrings(string s) {
                                                                
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));   /* dp[i][j]: �� i �� j �����Χ��([i,j])���Ӵ��ǲ���һ�����Ĵ� */
        int result = 0;
        for (int i = s.size() - 1; i >= 0; i--) {                           /* ����˳��ȡ���ڵ��ƹ�ʽ */
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j]) {                                         /* ������������� */
                    if (j - i <= 1) {                                       /* ���1 �� ���2 */
                        dp[i][j] = true;
                        result++;
                    }
                    else {
                        if (dp[i + 1][j - 1] == true) {                     /* ���3 */
                            dp[i][j] = dp[i + 1][j - 1];
                            result++;
                        }

                    }
                }
            }
        }
        return result;
    }
};