class Solution {
public:
    bool isValid(char& c) {
        if (c >= 'a' && c <= 'z') return true;
        else if (c >= 'A' && c <= 'Z') {
            c = tolower(c);
            return true;
        } else if (c >= '0' && c <= '9') return true;
        return false;
    }

    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {                                  /* 回文串使用 < 即可 */
            while (left < right && !isValid(s[left])) left++;
            while (left < right && !isValid(s[right])) right--;

            if (s[left] == s[right]) {
                left++;right--;
            } else return false;
        }
        return true;
    }
};