/* KMP 算法 */

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


        if (next[s.size() - 1] != 0 && s.size() % (s.size() - next[s.size() - 1]) == 0) {   /* 注意判断条件：
                                                                                             * 1.只与 next[s.size() - 1] 有关 
                                                                                             * 2.next[s.size() - 1] != 0 
                                                                                             */
            return true;
        }
        return false;
    }
};

/* 移动匹配 */

class Solution {
public:

    bool repeatedSubstringPattern(string s) {
        if (s.size() == 0) {
            return false;
        }

        string ss = s + s;                      /* 在 s+s 中找到 s */
        ss.erase(ss.begin());
        ss.erase(ss.end() - 1);

        if (ss.find(s) != std::string::npos) {
            return true;
        }
        return false;
    }
};