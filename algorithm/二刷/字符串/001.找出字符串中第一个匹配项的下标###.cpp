class Solution {
public:
    void getNext(int* next, const string& s) {
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.size(); i++) {
            while (j > 0 && s[j] != s[i]) {
                j = next[j - 1];
            }
            if (s[j] == s[i]) {
                j++;
            }
            next[i] = j;
        }
    }

    int strStr(string haystack, string needle) {
        int next[needle.size()];
        int j = 0;
        getNext(next, needle);

        for (int i = 0; i < haystack.size(); i++) {
            while (j > 0 && needle[j] != haystack[i]) {
                j = next[j - 1];
            }
            if (needle[j] == haystack[i]) {
                j++;
            }
            if (j == needle.size()) return i - j + 1;
        }
        return -1;
    }
};
