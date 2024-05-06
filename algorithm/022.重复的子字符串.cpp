/* KMP �㷨 */

class Solution {
public:

    bool repeatedSubstringPattern(string s) {
        if (s.size() == 0) {
            return false;
        }

        int next[s.size()];
        next[0] = 0;
        int j = 0;

        for (int i = 1; i < s.size(); i++) {
            while (j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }


        if (next[s.size() - 1] != 0 && s.size() % (s.size() - next[s.size() - 1]) == 0) {   /* ע���ж�������
                                                                                             * 1.ֻ�� next[s.size() - 1] �й� 
                                                                                             * 2.next[s.size() - 1] != 0 
                                                                                             */
            return true;
        }
        return false;
    }
};

/* �ƶ�ƥ�� */

class Solution {
public:

    bool repeatedSubstringPattern(string s) {
        if (s.size() == 0) {
            return false;
        }

        string ss = s + s;                      /* �� s+s ���ҵ� s */
        ss.erase(ss.begin());
        ss.erase(ss.end() - 1);

        if (ss.find(s) != std::string::npos) {
            return true;
        }
        return false;
    }
};