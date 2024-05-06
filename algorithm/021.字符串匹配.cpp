class Solution {
public:
    /*
     * i:要匹配的下标。
     * j:要匹配的下标及前面子串的最长相等前后缀的长度。
     */
    void getNext(int* next, const string& s) {
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.size(); i++) {        
            while (j > 0 && s[j] != s[i]) {
                j = next[j - 1];                /* 使用 KMP 算法 */
            }
            if (s[i] == s[j]) {
                j++;                            /* 包括 i 在内的最长相等前后缀的长度 */
            }
            next[i] = j;                        /* next[i] 保存包括 i 在内的最长相等前后缀的长度 */
        }
    }

    int strStr(string haystack, string needle) {
        int next[needle.size()];
        int j = 0;
        getNext(next, needle);                          /* 初始化 next 数组 */

        for (int i = 0; i < haystack.size(); i++) {
            while (j > 0 && needle[j] != haystack[i]) {
                j = next[j - 1];                        /* 使用 KMP 算法 */
            }
            if (haystack[i] == needle[j]) {
                j++;                                    /* 要匹配的下标++ */
            }
            if (j == needle.size()) {
                return (i - needle.size() + 1);         /* 返回第一个匹配字符串的起始位置(i 此时在匹配字符串的最后一个字符位置) */
            }
        }
        return -1;
    }
};