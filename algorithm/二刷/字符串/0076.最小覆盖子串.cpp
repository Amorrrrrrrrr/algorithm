/* 滑动窗口 + 哈希表 */
class Solution {
public:
    bool isBaohan(const vector<int>& s, const vector<int>& t) { /* 超出内存限制 */
        for (int i = 0; i < s.size(); i++) {
            if (s[i] < t[i]) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        vector<int> tVec(128, 0);
        vector<int> sVec(128, 0);
        for (int i = 0; i < t.size(); i++) {
            tVec[t[i]]++;
        }
        string ret;

        int slow = 0;
        for (int fast = 0; fast < s.size(); fast++) {
            sVec[s[fast]]++;

            while (fast - slow + 1 >= t.size() && isBaohan(sVec, tVec)) {
                if (ret.size() != 0 && ret.size() <= fast - slow + 1) {}
                else ret = s.substr(slow, fast - slow + 1);                 /* 原因：字符串分割太多次了 */

                sVec[s[slow]]--;
                slow++;
            }

        }
        return ret;
    }
};


class Solution {
public:

    string minWindow(string s, string t) {
        int tVec[128] = { 0 };
        int sVec[128] = { 0 };

        for (int i = 0; i < t.size(); i++) {
            tVec[t[i]]++;
        }
        string ret;

        int slow = 0;
        int len = 0;
        for (int fast = 0; fast < s.size(); fast++) {
            if (tVec[s[fast]] > sVec[s[fast]]) {                            /* 只有 t 的哈希表 > s 的哈希表时才 len++ */
                len++;
            }
            sVec[s[fast]]++;

            while (len == t.size()) {
                sVec[s[slow]]--;
                if (tVec[s[slow]] > sVec[s[slow]]) {                        /* 只有 t 的哈希表 > s 的哈希表时才记录结果 */
                    if (ret.empty() || ret.size() > fast - slow + 1) {      /* 记录结果 */
                        ret = s.substr(slow, fast - slow + 1);
                    }

                    len--;
                }
                slow++;
            }
        }
        return ret;
    }
};