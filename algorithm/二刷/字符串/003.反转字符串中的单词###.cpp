
/* 整体翻转 + 局部翻转 */
class Solution {
public:
    // 反转字符串 s[start, end]
    void reverse(string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    // 去除多余空格
    void eraseExaSpace(string& s) {
        int slow = 0;
        for (int fast = 0; fast < s.size();) {
            if (s[fast] == ' ') {
                if (slow != 0) {
                    s[slow] = ' ';
                    slow++;
                }
                while (fast < s.size() && s[fast] == ' ') fast++;       /* 循环去除空格 */
            } else {
                s[slow] = s[fast];
                slow++;
                fast++;
            }
        }
        if (s[slow - 1] == ' ') s.resize(slow - 1);                     /* 保证字符串末尾没空格 */
        else s.resize(slow);   
    }
    string reverseWords(string s) {
        eraseExaSpace(s); 
        reverse(s, 0, s.size() - 1);
        int start = 0;
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') {                         /* 遇到空格/末尾就反转字符串 */
                reverse(s, start, i - 1);
                start = i + 1;
            }
        }
        return s;
    }
};