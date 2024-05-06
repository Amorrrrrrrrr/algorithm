class Solution {
public:
    /*
     * i:Ҫƥ����±ꡣ
     * j:Ҫƥ����±꼰ǰ���Ӵ�������ǰ��׺�ĳ��ȡ�
     */
    void getNext(int* next, const string& s) {
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.size(); i++) {        
            while (j > 0 && s[j] != s[i]) {
                j = next[j - 1];                /* ʹ�� KMP �㷨 */
            }
            if (s[i] == s[j]) {
                j++;                            /* ���� i ���ڵ�����ǰ��׺�ĳ��� */
            }
            next[i] = j;                        /* next[i] ������� i ���ڵ�����ǰ��׺�ĳ��� */
        }
    }

    int strStr(string haystack, string needle) {
        int next[needle.size()];
        int j = 0;
        getNext(next, needle);                          /* ��ʼ�� next ���� */

        for (int i = 0; i < haystack.size(); i++) {
            while (j > 0 && needle[j] != haystack[i]) {
                j = next[j - 1];                        /* ʹ�� KMP �㷨 */
            }
            if (haystack[i] == needle[j]) {
                j++;                                    /* Ҫƥ����±�++ */
            }
            if (j == needle.size()) {
                return (i - needle.size() + 1);         /* ���ص�һ��ƥ���ַ�������ʼλ��(i ��ʱ��ƥ���ַ��������һ���ַ�λ��) */
            }
        }
        return -1;
    }
};