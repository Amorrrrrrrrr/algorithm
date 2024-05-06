/* 思路1：移动匹配 */
class Solution {
public:

    bool repeatedSubstringPattern(string s) {
        if (s.size() == 0) {
            return false;
        }

        string ss = s + s;
        ss.erase(ss.begin());                       /* 抛头去尾 */
        ss.erase(ss.end() - 1);

        if (ss.find(s) != std::string::npos) {
            return true;
        }
        return false;
    }
};

/* 思路2：KMP 算法 */
class Solution {
public:
    void getNext(int* next, const string& s) {
        int j = 0;
        next[j] = 0;
        for (int i = 1; i < s.size(); i++) {
            while (j > 0 && s[j] != s[i]) {
                j = next[j - 1];
            }
            if (s[j] == s[i]) j++;
            next[i] = j;
        }
    }
    bool repeatedSubstringPattern(string s) {                               
        if (s.size() <= 1) return false;
        int next[s.size()];
        getNext(next, s);
        if (next[s.size() - 1] == 0) return false;                          /* 只使用 next[size - 1] */

        return next[s.size() - 1] % (s.size() - next[s.size() - 1]) == 0;
    }
};