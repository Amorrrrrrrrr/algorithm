class Solution {
public:
    void reverseString(string& s, int begin, int end) {
        int left = begin;
        int right = end - 1;
        while (left < right) {
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++; right--;
        }
    }

    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k) {             /* for 循环每次递增 2k */
            if (i + k - 1 <= s.size() - 1) {                    /* 边界条件 */
                reverseString(s, i, i + k);
            }
            else {
                reverseString(s, i, s.size());
            }
        }
        return s;
    }
};

/* 最佳答案 */
class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
            // 1. 每隔 2k 个字符的前 k 个字符进行反转
            // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k);
            }
            else {
                // 3. 剩余字符少于 k 个，则将剩余字符全部反转。
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};