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

    string reverseWords(string s) {
        int fast = 0;
        int slow = 0;
        for (; fast < s.size(); fast++) {                           
            if (s[fast] != ' ') {                               /* 删除所有空格 */
                if (slow != 0) {                                /* 手动添加空格 */
                    s[slow] = ' ';
                    slow++;
                }
                while (fast < s.size() && s[fast] != ' ') {     /* 补上该单词 */
                    s[slow] = s[fast];
                    slow++;
                    fast++;
                }
            }
        }
        s.resize(slow);

        reverseString(s, 0, s.size());
        int left = 0;
        int right = 0;
        for (; right < s.size(); right++) {
            if (s[right] == ' ') {
                reverseString(s, left, right);
                left = right + 1;
            }
        }
        reverseString(s, left, right);

        return s;
    }
};